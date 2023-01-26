#include "STDInclude.hpp"

namespace Utils
{
	namespace Cryptography
	{
		bool SALSA20::encrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData)
		{
			ECRYPT_ctx x;
			ECRYPT_keysetup(&x, key, 32 * 8, 0);
			ECRYPT_ivsetup(&x, iv);
			ECRYPT_encrypt_bytes(&x, inData, outData, length);

			return true;
		}

		bool SALSA20::decrypt(const uint8_t* inData, size_t length, uint8_t* iv, uint8_t* key, uint8_t* outData)
		{
			ECRYPT_ctx x;
			ECRYPT_keysetup(&x, key, 32 * 8, 0);
			ECRYPT_ivsetup(&x, iv);
			ECRYPT_decrypt_bytes(&x, inData, outData, length);

			return true;
		}
	}
}
