#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Game/FastFile.hpp"

namespace Game
{
	class Stream
	{
	public:
		// This represents packed offset in streams:
		// - lowest 29 bits store the value/offset
		// - highest 3 bits store the stream
		//
		// T6 only uses 8 streams instead of 16 (former CODs).
		// So only 3 bits are needed to store the stream (instead of 4).
		// log2(8) = 3
#pragma warning(push)
#pragma warning(disable: 4201)
		class Offset
		{
		public:
			union
			{
				struct
				{
					uint32_t value : 29;
					XFILE_BLOCK_TYPES stream : 3;
				};
				uint32_t packed;
			};

			Offset() : packed(0) {};
			Offset(XFILE_BLOCK_TYPES _stream, uint32_t _value) : value(_value), stream(_stream) {};

			// The game needs it to be incremented
			uint32_t getPackedValue() { return this->packed + 1; };
		};
#pragma warning(pop)

		Stream(size_t size);

		template<typename T>
		void writeArray(T*& obj, size_t size = 1)
		{
			this->write(obj, sizeof(T) * size);
		}

		template<typename T>
		void write(T& obj)
		{
			this->write(&obj, sizeof(T));
		}

		template<typename T>
		void writeRVal(T obj)
		{
			this->write(&obj, sizeof(T));
		}

		void writeString(const std::string& string);

		void pushBlock(int block);
		void popBlock();

		void write(const void* data, size_t length);
		std::string& getBuffer();

		int getBlockSize(int block);
		int getBlock();

		void align(int subBinaryPower);

		template<typename T>
		static void ResetPointer(T*& pointer)
		{
			pointer = reinterpret_cast<T*>(-1);
		}

		void* findBasePointer(const void* pointer);
		void* findPointer(const void* pointer);
		void storePointer(const void* pointer, size_t length);

		void setIndexStart(int start);
		int getIndexStart();

		bool hasPointer(const void* pointer);
		uint32_t safeGetPointer(const void* pointer);

	private:
		class Pointer
		{
		public:
			int block;
			int blockSize;
			void* pointer;
			size_t length;
		};

		int indexStart;

		std::string buffer;
		std::vector<int> blockStack;
		unsigned int blockSizes[Game::MAX_XFILE_COUNT];

		std::map<const void*, Pointer> pointerMap;

		void increaseBlockSize(size_t size);
	};
}
