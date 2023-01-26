#include "STDInclude.hpp"

#include "Game/Zone.hpp"

#include "Core/Components/Console.hpp"

namespace Game
{
	Stream::Stream(size_t size)
	{
		this->buffer.reserve(size);
		ZeroMemory(&this->blockSizes, sizeof(this->blockSizes));
	}

	void Stream::writeString(const std::string& string)
	{
		this->write(string.data(), string.size());
		this->writeRVal(0ui8);
	}

	void Stream::write(const void* data, size_t length)
	{
		auto block = this->getBlock();
		if (block == -1 || block == 0 || block == 5 || block == 6)
		{
			this->buffer.append(PCHAR(data), length);
		}

		this->increaseBlockSize(length);
	}

	std::string& Stream::getBuffer()
	{
		return this->buffer;
	}

	void Stream::pushBlock(int block)
	{
		this->blockStack.push_back(block);
	}

	void Stream::popBlock()
	{
		this->blockStack.pop_back();
	}

	void Stream::align(int subBinaryPower)
	{
		int block = Stream::getBlock();
		if (block == -1) return;

		this->blockSizes[block] = ~subBinaryPower & (this->blockSizes[block] + subBinaryPower);
	}

	int Stream::getBlockSize(int block)
	{
		if (block < 0 || block >= ARRAYSIZE(this->blockSizes)) return 0;
		return this->blockSizes[block];
	}

	int Stream::getBlock()
	{
		if (!this->blockStack.empty())
		{
			int block = this->blockStack.back();
			if (block >= 0 && block < ARRAYSIZE(this->blockSizes))
			{
				return block;
			}
		}
		return -1;
	}

	void Stream::increaseBlockSize(size_t size)
	{
		int block = Stream::getBlock();
		if (block == -1) return;

		this->blockSizes[block] += size;
	}

	void* Stream::findBasePointer(const void* pointer)
	{
		auto sourcePointer = PCHAR(pointer);

		for (auto& entry : this->pointerMap)
		{
			auto targetPointer = PCHAR(entry.first);
			if (sourcePointer >= targetPointer && sourcePointer < (targetPointer + entry.second.length))
			{
				return targetPointer;
			}
		}

		return nullptr;
	}

	void* Stream::findPointer(const void* pointer)
	{
		auto basePointer = this->findBasePointer(pointer);
		if (!basePointer) return nullptr;

		size_t offset = PCHAR(pointer) - PCHAR(basePointer);

		return PCHAR(this->pointerMap[basePointer].pointer) + offset;
	}

	void Stream::storePointer(const void* pointer, size_t length)
	{
		Pointer mappedPointer;
		mappedPointer.block = this->getBlock();
		mappedPointer.blockSize = this->getBlockSize(mappedPointer.block);
		mappedPointer.length = length;
		mappedPointer.pointer = this->buffer.data() + this->buffer.size();

		this->pointerMap[pointer] = mappedPointer;
	}

	void Stream::setIndexStart(int start)
	{
		this->indexStart = start;
	}

	int Stream::getIndexStart()
	{
		return this->indexStart;
	}

	bool Stream::hasPointer(const void* pointer)
	{
		return this->findBasePointer(pointer) != nullptr;
	}

	uint32_t Stream::safeGetPointer(const void* pointer)
	{
		void* basePointer = this->findBasePointer(pointer);
		if (!basePointer) return NULL;

		size_t offset = PCHAR(pointer) - PCHAR(basePointer);
		auto& mappedPointer = this->pointerMap[basePointer];

		Stream::Offset gameOffset;
		gameOffset.stream = Game::XFILE_BLOCK_TYPES(mappedPointer.block);
		gameOffset.value = mappedPointer.blockSize + offset;

		return gameOffset.getPackedValue();
	}
}
