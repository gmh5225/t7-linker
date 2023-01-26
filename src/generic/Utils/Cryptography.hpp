#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#define HOOK_JUMP true
#define HOOK_CALL false

namespace Utils
{
	namespace Cryptography
	{
		std::string GetRandomBytes(size_t size);
		void GetRandomBytes(void* data, size_t size);

		template<typename T> T Random()
		{
			T data;
			GetRandomBytes(&data, sizeof(data));
			return data;
		}

		class IEncryption
		{
		public:
			virtual ~IEncryption() {};
			virtual bool encrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData) = 0;
			virtual bool decrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData) = 0;

			virtual std::string encryptString(std::string data, uint8_t* iv, uint8_t* key)
			{
				if (!iv || !key) return std::string();

				if (!this->encrypt(reinterpret_cast<const uint8_t*>(data.data()), data.size(), iv, key, reinterpret_cast<uint8_t*>(const_cast<char*>(data.data()))))
				{
					data.clear();
				}

				return data;
			}

			virtual bool encryptData(const void* inData, size_t length, const void* iv, const void* key, const void* outData)
			{
				return this->encrypt(reinterpret_cast<const uint8_t*>(inData), length, reinterpret_cast<uint8_t*>(const_cast<void*>(iv)), reinterpret_cast<uint8_t*>(const_cast<void*>(key)), reinterpret_cast<uint8_t*>(const_cast<void*>(outData)));
			}

			virtual std::string decryptString(std::string data, const void* iv, uint8_t* key)
			{
				if (!this->decrypt(reinterpret_cast<const uint8_t*>(data.data()), data.size(),reinterpret_cast<uint8_t*>(const_cast<void*>(iv)), key, reinterpret_cast<uint8_t*>(const_cast<char*>(data.data()))))
				{
					data.clear();
				}

				return data;
			}

			virtual bool decryptData(const void* inData, size_t length, const void* iv, const void* key, const void* outData)
			{
				return this->decrypt(reinterpret_cast<const uint8_t*>(inData), length, reinterpret_cast<uint8_t*>(const_cast<void*>(iv)), reinterpret_cast<uint8_t*>(const_cast<void*>(key)), reinterpret_cast<uint8_t*>(const_cast<void*>(outData)));
			}
		};

		class IHash
		{
		public:
			virtual ~IHash() {};
			virtual std::string compute(const uint8_t* inData, size_t length) = 0;

			virtual std::string computeData(const void* inData, size_t length)
			{
				return this->compute(reinterpret_cast<const uint8_t*>(inData), length);
			}

			virtual std::string computeString(std::string data/*, bool hex = false*/)
			{
				// TODO: Implement hex
				return this->compute(reinterpret_cast<const uint8_t*>(data.data()), data.size());
			}
		};

		class IEmbeddableHash : public IHash
		{
		public:
			virtual int getHash()
			{
				assert(this->hash != -1);
				return this->hash;
			}

		protected:
			int hash;
		};

		template<int keyLength> class CBC : public IEncryption
		{
		public:
			bool encrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData) override
			{
				if (!inData || !length || !iv || !key || !outData) return false;
				assert(this->cipher != -1);

				symmetric_CBC cbc;
				cbc_start(this->cipher, iv, key, this->getKeyLength(), 0, &cbc);
				bool result = cbc_encrypt(inData, outData, static_cast<unsigned long>(length), &cbc) == CRYPT_OK;
				cbc_done(&cbc);

				return result;
			}

			bool decrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData) override
			{
				if (!inData || !length || !iv || !key || !outData) return false;
				assert(this->cipher != -1);

				symmetric_CBC cbc;
				cbc_start(this->cipher, iv, key, this->getKeyLength(), 0, &cbc);
				bool result = cbc_decrypt(inData, outData, static_cast<unsigned long>(length), &cbc) == CRYPT_OK;
				cbc_done(&cbc);

				return result;
			}

		protected:
			int cipher = -1;

		private:
			int getKeyLength() { return keyLength; }
		};

		class AES : public CBC<16>
		{
		public:
			AES();
		};

		class DES3 : public CBC<24>
		{
		public:
			DES3();
		};

		class SHA1 : public IEmbeddableHash
		{
		public:
			SHA1();
			virtual std::string compute(const uint8_t* inData, size_t length) override;
		};

		class SHA256 : public IEmbeddableHash
		{
		public:
			SHA256();
			virtual std::string compute(const uint8_t* inData, size_t length) override;
		};

		class SHA512 : public IEmbeddableHash
		{
		public:
			SHA512();
			virtual std::string compute(const uint8_t* inData, size_t length) override;
		};

		class MD5 : public IEmbeddableHash
		{
		public:
			MD5();
			virtual std::string compute(const uint8_t* inData, size_t length) override;
		};

		class Tiger : public IEmbeddableHash
		{
		public:
			Tiger();
			virtual std::string compute(const uint8_t* inData, size_t length) override;
		};

		template<typename Hash> class HMac
		{
			static_assert(std::is_base_of<IEmbeddableHash, Hash>::value, "Hash must be embeddable");

		public:
			HMac()
			{
				this->hash.reset(new Hash);
			}

			std::string compute(std::string key, std::string data)
			{
				unsigned long outLen = 20;
				std::basic_string<uint8_t> buffer;
				buffer.resize(24);

				hmac_state state;
				hmac_init(&state, this->hash->getHash(), reinterpret_cast<const uint8_t*>(key.data()), static_cast<unsigned long>(key.size()));
				hmac_process(&state, reinterpret_cast<const uint8_t*>(data.data()), static_cast<unsigned long>(data.size()));
				hmac_done(&state, const_cast<uint8_t*>(buffer.data()), &outLen);

				return std::string(reinterpret_cast<const char*>(buffer.data()), outLen);
			}

		private:
			std::unique_ptr<IEmbeddableHash> hash;
		};

		class ECC
		{
		public:
			class Key
			{
			public:
				Key() : keyStorage(new ecc_key)
				{
					ZeroMemory(this->getKeyPtr(), sizeof(*this->getKeyPtr()));
				};
				Key(ecc_key* key) : Key() { if (key) std::memmove(this->getKeyPtr(), key, sizeof(*key)); };
				Key(ecc_key key) : Key(&key) {};
				~Key()
				{
					if (this->keyStorage.use_count() <= 1)
					{
						this->free();
					}
				};

				bool isValid()
				{
					return (!Utils::Memory::IsSet(this->getKeyPtr(), 0, sizeof(*this->getKeyPtr())));
				}

				ecc_key* getKeyPtr()
				{
					return this->keyStorage.get();
				}

				std::string getPublicKey()
				{
					uint8_t buffer[512] = { 0 };
					DWORD length = sizeof(buffer);

					if (ecc_ansi_x963_export(this->getKeyPtr(), buffer, &length) == CRYPT_OK)
					{
						return std::string(reinterpret_cast<char*>(buffer), length);
					}

					return "";
				}

				void set(std::string pubKeyBuffer)
				{
					this->free();

					if (ecc_ansi_x963_import(reinterpret_cast<const uint8_t*>(pubKeyBuffer.data()), ULONG(pubKeyBuffer.size()), this->getKeyPtr()) != CRYPT_OK)
					{
						ZeroMemory(this->getKeyPtr(), sizeof(*this->getKeyPtr()));
					}
				}

				void deserialize(std::string key)
				{
					this->free();

					/*if (ecc_import(reinterpret_cast<const uint8_t*>(key.data()), ULONG(key.size()), this->getKeyPtr()) != CRYPT_OK)
					{
						ZeroMemory(this->getKeyPtr(), sizeof(*this->getKeyPtr()));
					}*/
				}

				std::string serialize(int type = PK_PRIVATE)
				{
					uint8_t buffer[4096] = { 0 };
					DWORD length = sizeof(buffer);

					if (ecc_export(buffer, &length, type, this->getKeyPtr()) == CRYPT_OK)
					{
						return std::string(reinterpret_cast<char*>(buffer), length);
					}

					return "";
				}

				void free()
				{
					if (this->isValid())
					{
						ecc_free(this->getKeyPtr());
					}

					ZeroMemory(this->getKeyPtr(), sizeof(*this->getKeyPtr()));
				}

				bool operator==(Key& key)
				{
					return (this->isValid() && key.isValid() && this->serialize(PK_PUBLIC) == key.serialize(PK_PUBLIC));
				}

			private:
				std::shared_ptr<ecc_key> keyStorage;
			};

			static Key GenerateKey(int bits);
			static std::string SignMessage(Key key, std::string message);
			static bool VerifyMessage(Key key, std::string message, std::string signature);
		};

		class RSA
		{
		public:
			class Key
			{
			public:
				Key() : keyStorage(new rsa_key)
				{
					ZeroMemory(this->getKeyPtr(), sizeof(*this->getKeyPtr()));
				};
				Key(rsa_key* key) : Key() { if (key) std::memmove(this->getKeyPtr(), key, sizeof(*key)); };
				Key(rsa_key key) : Key(&key) {};
				~Key()
				{
					if (this->keyStorage.use_count() <= 1)
					{
						this->free();
					}
				};

				rsa_key* getKeyPtr()
				{
					return this->keyStorage.get();
				}

				bool isValid()
				{
					return (!Utils::Memory::IsSet(this->getKeyPtr(), 0, sizeof(*this->getKeyPtr())));
				}

				void free()
				{
					if (this->isValid())
					{
						rsa_free(this->getKeyPtr());
					}

					ZeroMemory(this->getKeyPtr(), sizeof(*this->getKeyPtr()));
				}

			private:
				std::shared_ptr<rsa_key> keyStorage;
			};

			static Key GenerateKey(int bits);
			static std::string SignMessage(Key key, std::string message);
			static bool VerifyMessage(Key key, std::string message, std::string signature);
		};
	}
}
