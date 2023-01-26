#include "STDInclude.hpp"

namespace Utils
{
	namespace Cryptography
	{
		StaticInitializer _([]()
		{
			// crypt_mp_init("l");
            

			register_prng(&sprng_desc);

			register_hash(&sha1_desc);
			register_hash(&sha256_desc);
			register_hash(&sha512_desc);
			register_hash(&md5_desc);
			register_hash(&tiger_desc);

			register_cipher(&aes_desc);
			register_cipher(&des3_desc);
		});

		std::string GetRandomBytes(size_t size)
		{
			Utils::Memory::Allocator allocator;
			char* data = allocator.allocateArray<char>(size);

			GetRandomBytes(data, size);

			return std::string(data, size);
		}

		void GetRandomBytes(void* data, size_t size)
		{
			static std::random_device rd;
			static std::mt19937_64 gen(rd());
			static std::uniform_int_distribution<unsigned long> dis;

			char* dataPtr = reinterpret_cast<char*>(data);
			while (size > 0)
			{
				unsigned long num = dis(gen);
				size_t len = std::min(size, sizeof(unsigned long));

				std::memmove(dataPtr, &num, len);

				dataPtr += len;
				size -= len;
			}
		}

		AES::AES()
		{
			this->cipher = find_cipher("aes");
		}

		DES3::DES3()
		{
			this->cipher = find_cipher("3des");
		}

		SHA1::SHA1()
		{
			this->hash = find_hash("sha1");
		}

		std::string SHA1::compute(const uint8_t* inData, size_t length)
		{
			std::string result;
			result.resize(sha1_desc.hashsize);

			hash_state state;
			sha1_init(&state);
			sha1_process(&state, inData,static_cast<unsigned long>(length));
			sha1_done(&state, reinterpret_cast<uint8_t*>(const_cast<char*>(result.data())));

			return result;
		}

		SHA256::SHA256()
		{
			this->hash = find_hash("sha256");
		}

		std::string SHA256::compute(const uint8_t* inData, size_t length)
		{
			std::string result;
			result.resize(sha256_desc.hashsize);

			hash_state state;
			sha256_init(&state);
			sha256_process(&state, inData, static_cast<unsigned long>(length));
			sha256_done(&state, reinterpret_cast<uint8_t*>(const_cast<char*>(result.data())));

			return result;
		}

		SHA512::SHA512()
		{
			this->hash = find_hash("sha512");
		}

		std::string SHA512::compute(const uint8_t* inData, size_t length)
		{
			std::string result;
			result.resize(sha512_desc.hashsize);

			hash_state state;
			sha512_init(&state);
			sha512_process(&state, inData, static_cast<unsigned long>(length));
			sha512_done(&state, reinterpret_cast<uint8_t*>(const_cast<char*>(result.data())));

			return result;
		}

		MD5::MD5()
		{
			this->hash = find_hash("md5");
		}

		std::string MD5::compute(const uint8_t* inData, size_t length)
		{
			std::string result;
			result.resize(md5_desc.hashsize);

			hash_state state;
			md5_init(&state);
			md5_process(&state, inData, static_cast<unsigned long>(length));
			md5_done(&state, reinterpret_cast<uint8_t*>(const_cast<char*>(result.data())));

			return result;
		}

		Tiger::Tiger()
		{
			this->hash = find_hash("tiger");
		}

		std::string Tiger::compute(const uint8_t* inData, size_t length)
		{
			std::string result;
			result.resize(tiger_desc.hashsize);

			hash_state state;
			tiger_init(&state);
			tiger_process(&state, inData, static_cast<unsigned long>(length));
			tiger_done(&state, reinterpret_cast<uint8_t*>(const_cast<char*>(result.data())));

			return result;
		}

		ECC::Key ECC::GenerateKey(int /*bits*/)
		{
			ECC::Key key;
			// ecc_make_key(nullptr, find_prng("sprng"), bits / 8, key.getKeyPtr());
			return key;
		}

		std::string ECC::SignMessage(Key key, std::string message)
		{
			if (!key.isValid()) return "";

			uint8_t buffer[512];
			DWORD length = sizeof(buffer);

			ecc_sign_hash(reinterpret_cast<const uint8_t*>(message.data()), ULONG(message.size()), buffer, &length, nullptr, find_prng("sprng"), key.getKeyPtr());

			return std::string(reinterpret_cast<char*>(buffer), length);
		}

		bool ECC::VerifyMessage(Key key, std::string message, std::string signature)
		{
			if (!key.isValid()) return false;

			int result = 0;
			return (ecc_verify_hash(reinterpret_cast<const uint8_t*>(signature.data()), ULONG(signature.size()), reinterpret_cast<const uint8_t*>(message.data()), ULONG(message.size()), &result, key.getKeyPtr()) == CRYPT_OK && result != 0);
		}

		RSA::Key RSA::GenerateKey(int bits)
		{
			RSA::Key key;
			rsa_make_key(nullptr, find_prng("sprng"), bits / 8, 65537, key.getKeyPtr());
			return key;
		}

		std::string RSA::SignMessage(RSA::Key key, std::string message)
		{
			if (!key.isValid()) return "";

			uint8_t buffer[512];
			DWORD length = sizeof(buffer);
			rsa_sign_hash(reinterpret_cast<const uint8_t*>(message.data()), ULONG(message.size()), buffer, &length, NULL, find_prng("sprng"), find_hash("sha1"), 0, key.getKeyPtr());

			return std::string(reinterpret_cast<char*>(buffer), length);
		}

		bool RSA::VerifyMessage(Key key, std::string message, std::string signature)
		{
			if (!key.isValid()) return false;

			int result = 0;
			return (rsa_verify_hash(reinterpret_cast<const uint8_t*>(signature.data()), ULONG(signature.size()), reinterpret_cast<const uint8_t*>(message.data()), ULONG(message.size()), find_hash("sha1"), 0, &result, key.getKeyPtr()) == CRYPT_OK && result != 0);
		}
	}
}
