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
		class SALSA20 : public IEncryption
		{
		public:
			virtual bool encrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData) override;
			virtual bool decrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData) override;
		};
	}
}
