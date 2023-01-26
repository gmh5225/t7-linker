#include "STDInclude.hpp"

#include "Game/FastFile.hpp"

#include "Core/Components/Console.hpp"

namespace Game
{
	uint8_t FastFile::Key[32]
	{
		0x64, 0x1D, 0x8A, 0x2F,
		0xE3, 0x1D, 0x3A, 0xA6,
		0x36, 0x22, 0xBB, 0xC9,
		0xCE, 0x85, 0x87, 0x22,
		0x9D, 0x42, 0xB0, 0xF8,
		0xED, 0x9B, 0x92, 0x41,
		0x30, 0xBF, 0x88, 0xB6,
		0x5E, 0xDC, 0x50, 0xBE
	};

	FastFile::FastFile() { }
	FastFile::FastFile(std::string&& _buffer) : buffer(_buffer) { }
	FastFile::FastFile(const std::string& _buffer) : buffer(_buffer) { }

	FastFile::FastFile(Utils::IO::File file)
	{
		auto result = file.read();

		if (result.result)
		{
			this->buffer = result.data;
		}
		else
		{
			Components::Console::Error("Invalid FastFile path\n");
			this->buffer = std::string();
		}
	}

	const Game::XFileHeaderSigned* FastFile::getHeader()
	{
		if (this->buffer.empty()) return nullptr;
		return reinterpret_cast<const Game::XFileHeaderSigned*>(this->buffer.data());
	}

	size_t FastFile::getHeaderSize()
	{
		if (!this->isValid()) return 0;
		if (this->isSigned()) return sizeof(Game::XFileHeaderSigned);
		if (this->isUnsigned()) return sizeof(Game::XFileHeaderUnsigned);
		return sizeof(Game::XFileHeaderRaw);
	}

	bool FastFile::isValid()
	{
		auto header = this->getHeader();
		if (!header) return false;

		return (header->u.r.magic == XFILE_MAGIC_RAW || header->u.r.magic == XFILE_MAGIC_UNSIGNED || header->u.r.magic == XFILE_MAGIC_SIGNED) &&
			header->u.r.platform == Game::PLATFORM_PC;
	}

	bool FastFile::isEncrypted()
	{
		return this->isValid() && this->getHeader()->u.r.magic != XFILE_MAGIC_RAW;
	}

	bool FastFile::isSigned()
	{
		return this->isValid() && this->getHeader()->u.r.magic == XFILE_MAGIC_SIGNED;
	}

	bool FastFile::isUnsigned()
	{
		return this->isValid() && this->getHeader()->u.r.magic == XFILE_MAGIC_UNSIGNED;
	}

	FastFile FastFile::encrypt(std::string name)
	{
		if (!this->isValid()) return FastFile();
		if (this->isEncrypted()) return this->decrypt().encrypt(name); // Rename the FastFile

		auto headerSize = this->getHeaderSize();
		if (this->buffer.size() <= headerSize)
		{
			Components::Console::Error("Unable to sign FastFile. Buffer is invalid\n");
			return FastFile();
		}

		Game::XFileHeaderSigned header;
		ZeroMemory(&header, sizeof(header));
		header.u.r = this->getHeader()->u.r;
		header.u.r.magic = XFILE_MAGIC_SIGNED;
		header.u.identifier = XFILE_IV_MAGIC_IDENTIFIER;
		strncpy(header.u.name, name.data(), sizeof(header.u.name));

		std::string result;
		result.append(PCHAR(&header), sizeof(header));

		// As far as I remember, the game uses the IV table to generate the signature in the end.
		Utils::Memory::Allocator allocator;
		auto ivTable = allocator.allocateArray<uint8_t>(16000);

		BYTE ivPtr[8];
		DWORD ivCounter[4] = { 0, 0, 0, 0 };

		FastFile::SetupIVCounter(ivCounter);
		FastFile::FillIVTable(header.u.name, ivTable, 16000);

		Game::XFileBlock* currentBlock = reinterpret_cast<Game::XFileBlock*>(&this->buffer[headerSize]);

		Utils::Cryptography::SHA1 sha1;
		Utils::Cryptography::SALSA20 salsa20;

		for (int i = 0;; i++)
		{
			if (!currentBlock->size) break;

			FastFile::FillIV((i % 4), ivPtr, ivTable, ivCounter);

			std::string hash = sha1.computeData(currentBlock->data, currentBlock->size);
			salsa20.encrypt(currentBlock->data, currentBlock->size, ivPtr, FastFile::Key, currentBlock->data);

			result.append(PCHAR(&currentBlock->size), 4);
			result.append(PCHAR(currentBlock->data), currentBlock->size);

			FastFile::GenerateIV((i % 4), INT(hash.data()), ivTable, &ivCounter[0]);
			currentBlock = reinterpret_cast<Game::XFileBlock*>(PCHAR(currentBlock) + currentBlock->size + 4);
		}

		int size = DWORD(this->buffer.data() + this->buffer.size()) - DWORD(currentBlock) + 4;
		for (int i = 0; i < size; i++)
		{
			result.push_back(0);
		}

		return FastFile(result);
	}

	FastFile FastFile::decrypt()
	{
		if (!this->isValid()) return FastFile();
		if (!this->isEncrypted()) return *this;

		auto headerSize = this->getHeaderSize();
		if (this->buffer.size() <= headerSize)
		{
			Components::Console::Error("Unable to sign FastFile. Buffer is invalid\n");
			return FastFile();
		}

		Game::XFileHeaderRaw header;
		ZeroMemory(&header, sizeof(header));
		header = this->getHeader()->u.r;
		header.magic = XFILE_MAGIC_RAW;

		std::string result;
		result.append(PCHAR(&header), sizeof(header));

		Utils::Memory::Allocator allocator;
		auto ivTable = allocator.allocateArray<uint8_t>(16000);

		BYTE ivPtr[8];
		DWORD ivCounter[4] = { 0, 0, 0, 0 };

		FastFile::SetupIVCounter(ivCounter);
		FastFile::FillIVTable(this->getName().data(), ivTable, 16000);

		Game::XFileBlock* currentBlock = reinterpret_cast<Game::XFileBlock*>(&this->buffer[headerSize]);

		Utils::Cryptography::SHA1 sha1;
		Utils::Cryptography::SALSA20 salsa20;

		for (int i = 0;; i++)
		{
			if (!currentBlock->size) break;

			FastFile::FillIV((i % 4), ivPtr, ivTable, ivCounter);

			salsa20.decrypt(currentBlock->data, currentBlock->size, ivPtr, FastFile::Key, currentBlock->data);
			std::string hash = sha1.computeData(currentBlock->data, currentBlock->size);

			result.append(PCHAR(&currentBlock->size), 4);
			result.append(PCHAR(currentBlock->data), currentBlock->size);

			FastFile::GenerateIV((i % 4), INT(hash.data()), ivTable, &ivCounter[0]);
			currentBlock = reinterpret_cast<Game::XFileBlock*>(PCHAR(currentBlock) + currentBlock->size + 4);
		}

		int size = DWORD(this->buffer.data() + this->buffer.size()) - DWORD(currentBlock) + 4;
		for (int i = 0; i < size; i++)
		{
			result.push_back(0);
		}

		return FastFile(result);
	}

	FastFile FastFile::sign()
	{
		if (!this->isValid()) return FastFile();
		if (this->isSigned()) return *this;
		if (!this->isEncrypted())
		{
			Components::Console::Error("Unable to sign FastFile. It needs to be encrypted first\n");
			return FastFile();
		}

		auto headerSize = this->getHeaderSize();
		if (this->buffer.size() <= headerSize)
		{
			Components::Console::Error("Unable to sign FastFile. Buffer is invalid\n");
			return FastFile();
		}

		return this->decrypt().encrypt(this->getName());
	}

	FastFile FastFile::unsign()
	{
		if (!this->isValid()) return FastFile();
		if (this->isUnsigned()) return *this;
		if (!this->isEncrypted())
		{
			Components::Console::Error("Unable to unsign FastFile. It needs to be encrypted first\n");
			return FastFile();
		}

		auto headerSize = this->getHeaderSize();
		if (this->buffer.size() <= headerSize)
		{
			Components::Console::Error("Unable to unsign FastFile. Buffer is invalid\n");
			return FastFile();
		}

		std::string result;
		result.append(PCHAR(&this->getHeader()->u), sizeof(Game::XFileHeaderUnsigned));
		result.append(&this->buffer[headerSize], this->buffer.size() - headerSize);

		return FastFile(result);
	}

	FastFile FastFile::Compress(const std::string& zone)
	{
		Game::XFileHeaderRaw header;
		header.magic = XFILE_MAGIC_RAW;
		header.platform = Game::PLATFORM_PC;

		std::string buffer;
		buffer.reserve(zone.size());
		buffer.append(PCHAR(&header), sizeof(header));

		Utils::Memory::Allocator allocator;
		const size_t blockLimit = XFILE_CHUNK_SIZE + 1;
		uint8_t* blockBuffer = allocator.allocateArray<uint8_t>(blockLimit);

		uint8_t* stream = PUCHAR(zone.data());
		uint8_t* end = stream + zone.size();

		while (true)
		{
			z_stream strm = { 0 };
			int size = std::min(XFILE_BLOCK_SIZE, end - stream);
			int initialSize = size;

			// Dynamically store blocks, while constantly decreasing the block size.
			// The game has a 2-in-1-block system to store over sized blocks in 2 steps.
			// This is potentially unsafe, if the buffer exceeds the size of 2 blocks (doubt that's possible though).
			// Storing blocks this way breaks these potential vulnerabilities.
			while (true)
			{
				deflateInit2_(&strm, Z_BEST_COMPRESSION, Z_DEFLATED, -15, 1, Z_DEFAULT_STRATEGY, "1.2.3", sizeof(z_stream));

				strm.next_out = blockBuffer;
				strm.next_in = stream;
				strm.avail_out = XFILE_CHUNK_SIZE;
				strm.avail_in = size;

				int result = deflate(&strm, Z_FINISH);

				deflateEnd(&strm);

				if (result == Z_STREAM_END) break; // Success
				else if (result == Z_OK) // Overflow, write smaller block
				{
					size /= 2;
					if (size < 8)
					{
						Components::Console::Error("Unable to compress zone block. Minimum size reached!\n");
						return FastFile();
					}
				}
				else
				{
					Components::Console::Error("Unable to compress zone block. Error code %X\n", result);
					return FastFile();
				}
			}

			buffer.append(PCHAR(&strm.total_out), 4);
			buffer.append(PCHAR(blockBuffer), strm.total_out);

			stream += size;

			if (size != XFILE_BLOCK_SIZE && size == initialSize) break;
		}

		while (buffer.size() % 16) buffer.push_back(0);
		for (int i = 0; i < 80; ++i) buffer.push_back(0);

		return FastFile(buffer);
	}

	std::string FastFile::decompress()
	{
		if (!this->isValid()) return std::string();
		if (this->isEncrypted()) return this->decrypt().decompress();

		auto headerSize = this->getHeaderSize();
		if (this->buffer.size() <= headerSize)
		{
			Components::Console::Error("Unable to decompress zone. Buffer is invalid\n");
			return std::string();
		}

		uint8_t* stream = PUCHAR(&this->buffer[headerSize]);

		Utils::Memory::Allocator allocator;
		const size_t blockLimit = XFILE_CHUNK_SIZE + 1;
		uint8_t* blockBuffer = allocator.allocateArray<uint8_t>(blockLimit);

		std::string zone;

		while (true)
		{
			size_t blockLength = *PDWORD(stream);
			stream += 4;

			if (PCHAR(stream + blockLength) > PCHAR(this->buffer.data() + this->buffer.size()))
			{
				Components::Console::Error("Unable to decompress zone. Block exceeds buffer\n");
				return std::string();
			}

			if (!blockLength) break;

			z_stream strm = { 0 };
			inflateInit2_(&strm, -15, "1.2.3", sizeof(z_stream));

			strm.avail_in = blockLength;
			strm.next_in = stream;
			strm.avail_out = blockLimit;
			strm.next_out = blockBuffer;
			int result = inflate(&strm, Z_FULL_FLUSH);

			inflateEnd(&strm);
			stream += blockLength;

			if (result != Z_STREAM_END)
			{
				Components::Console::Error("Unable to decompress zone block. Error code %X\n", result);
				return std::string();
			}

			if (zone.empty())
			{
				auto zoneHeader = reinterpret_cast<Game::ZoneHeader*>(blockBuffer);
				zone.reserve(zoneHeader->xFile.size + XFILE_BLOCK_SIZE);
			}

			zone.append(PCHAR(blockBuffer), strm.total_out);
		}

		return zone;
	}

	FastFile::operator std::string()
	{
		return this->getBuffer();
	}

	std::string& FastFile::getBuffer()
	{
		return this->buffer;
	}

	std::string FastFile::getName()
	{
		if (!this->isValid()) return std::string();
		if (!this->isEncrypted()) return std::string();

		char name[sizeof(Game::XFileHeaderUnsigned::name) + 1] = { 0 };
		strncpy(name, this->getHeader()->u.name, sizeof(Game::XFileHeaderUnsigned::name));

		return name;
	}

	void FastFile::SetupIVCounter(DWORD* ivCounterPtr)
	{
		for (int i = 0; i < 4; i++)
		{
			ivCounterPtr[i] = 1;
		}
	}

	void FastFile::FillIV(int a1, BYTE* ivPtr, BYTE* ivTable, DWORD* ivCounterPtr)
	{
		int v1 = ((a1 + 4 * (ivCounterPtr[a1] - 1)) % 800 * 20);

		for (int i = 0; i < 8; ++i)
		{
			ivPtr[i] = ivTable[v1 + i];
		}
	}

	void FastFile::FillIVTable(const char* name, unsigned char* ivTable, size_t ivTableLength)
	{
		size_t nameLength = strlen(name);

		for (size_t i = 0; i < ivTableLength; i++)
		{
			ivTable[i] = name[i / 4 % nameLength];
		}
	}

	// TODO: Refactor that
	void FastFile::GenerateIV(int a1, int a2, BYTE* ivTable, DWORD* ivCounterPtr)
	{
		int v2 = 4;
		signed int v3 = 0;
		int v4;
		int v5;
		int v6;
		int v7;
		int v8;

		do
		{
			v4 = (a1 + v2 * ivCounterPtr[a1]) % 800 * 5;
			*(&ivTable[4 * v4 + 0] + v3) ^= *(BYTE*)(a2 + v3 + 0);
			v5 = (a1 + v2 * ivCounterPtr[a1]) % 800 * 5;
			*(&ivTable[4 * v5 + 1] + v3) ^= *(BYTE*)(a2 + v3 + 1);
			v6 = (a1 + v2 * ivCounterPtr[a1]) % 800 * 5;
			*(&ivTable[4 * v6 + 2] + v3) ^= *(BYTE*)(a2 + v3 + 2);
			v7 = (a1 + v2 * ivCounterPtr[a1]) % 800 * 5;
			*(&ivTable[4 * v7 + 3] + v3) ^= *(BYTE*)(a2 + v3 + 3);
			v8 = (a1 + v2 * ivCounterPtr[a1]) % 800 * 5;
			*(&ivTable[4 * v8 + 4] + v3) ^= *(BYTE*)(a2 + v3 + 4);
			v3 += 5;
		} while (v3 < 20);

		++ivCounterPtr[a1];
	}
}
