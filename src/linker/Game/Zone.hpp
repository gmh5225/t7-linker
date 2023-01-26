#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Game/Stream.hpp"
#include "Game/FastFile.hpp"

static_assert(sizeof(long) == 4);

namespace Game
{
	class Zone
	{
	public:
		void addAsset(Game::XAsset asset);
		void addAsset(Game::XAssetType type, Game::XAssetHeader header);

		void markAsset(Game::XAsset asset);
		void markAsset(Game::XAssetType type, Game::XAssetHeader header);

		void delayMarkAsset(Game::XAsset asset);
		void delayMarkAsset(Game::XAssetType type, Game::XAssetHeader header);

		void markScriptString(unsigned short scriptString);
		unsigned short mapScriptString(unsigned short scriptString);

		void addDependency(const std::string& zone);

		size_t getAssetCount();
		int getAssetIndex(void* pointer);

		FastFile build();

	private:
		Utils::Memory::Allocator allocator;

		std::vector<Game::XAsset> delayMarkedAssets;
		std::vector<Game::XAsset> markedAssets;
		std::vector<Game::XAsset> assets;
		std::vector<std::string> dependencies;
		std::vector<std::string> scriptStrings;
		std::map<unsigned short, unsigned int> scriptStringMap;

		void writeHeader(Stream& stream);
		void fixupHeader(Stream& stream);

		void writeScriptStrings(Stream& stream);
		void writeDependencies(Stream& stream);
		void writeAssets(Stream& stream);
	};
}
