#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Game/Game.hpp"

namespace Game
{
	class FastFile
	{
	public:
		FastFile();
		FastFile(const std::string& buffer);
		FastFile(std::string&& buffer);
		FastFile(Utils::IO::File file);

		FastFile encrypt(std::string name);
		FastFile decrypt();

		FastFile sign();
		FastFile unsign();

		static FastFile Compress(const std::string& zone);
		std::string decompress();

		bool isValid();

		bool isEncrypted();
		bool isSigned();
		bool isUnsigned();

		std::string& getBuffer();

		std::string getName();

		operator std::string();

	private:
		std::string buffer;

		const Game::XFileHeaderSigned* getHeader();
		size_t getHeaderSize();

		static uint8_t Key[32];

		static void SetupIVCounter(DWORD* ivCounterPtr);
		static void FillIV(int a1, BYTE* ivPtr, BYTE* ivTable, DWORD* ivCounterPtr);
		static void FillIVTable(const char* name, unsigned char* ivTable, size_t ivTableLength);
		static void GenerateIV(int a1, int a2, BYTE* ivTable, DWORD* ivCounterPtr);
	};
}
