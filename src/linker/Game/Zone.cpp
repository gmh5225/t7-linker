#include "STDInclude.hpp"

#include "Game/Zone.hpp"

#include "Core/Components/Linker.hpp"
#include "Core/Components/Console.hpp"

namespace Game
{
	void Zone::addAsset(Game::XAsset asset)
	{
		Components::Linker::SetZone(this);

		this->markedAssets.clear();

		Game::varXAsset = &asset;
		Game::Mark_XAsset();

		while (!this->delayMarkedAssets.empty())
		{
			auto delayedAssets = this->delayMarkedAssets;
			this->delayMarkedAssets.clear();

			for (auto& delayedAsset : delayedAssets)
			{
				Game::varXAsset = &delayedAsset;
				Game::Mark_XAsset();
			}
		}

		std::reverse(this->markedAssets.begin(), this->markedAssets.end());
		Utils::Merge(&this->assets, this->markedAssets);
		this->markedAssets.clear();

		Components::Linker::SetZone(nullptr);
	}

	void Zone::addAsset(Game::XAssetType type, Game::XAssetHeader header)
	{
		this->addAsset(Game::XAsset{ type, header });
	}

	void Zone::markAsset(Game::XAsset asset)
	{
		std::string name = Game::DB_GetXAssetName(&asset);
		for (auto& entry : this->assets)
		{
			if (entry.type == asset.type &&
				Game::DB_GetXAssetName(&entry) == name)
			{
				return;
			}
		}

		bool alreadyMarked = false;
		for (auto i = this->markedAssets.begin(); i != this->markedAssets.end(); ++i)
		{
			if (i->type == asset.type &&
				Game::DB_GetXAssetName(&*i) == name)
			{
				this->markedAssets.erase(i);
				alreadyMarked = true;
				break;
			}
		}

		this->markedAssets.push_back(asset);

		if (!alreadyMarked)
		{
			Components::Linker::DelayMarkAsset(&asset);
		}
	}

	void Zone::markAsset(Game::XAssetType type, Game::XAssetHeader header)
	{
		this->markAsset(Game::XAsset{ type, header });
	}

	void Zone::delayMarkAsset(Game::XAsset asset)
	{
		this->delayMarkedAssets.push_back(asset);
	}

	void Zone::delayMarkAsset(Game::XAssetType type, Game::XAssetHeader header)
	{
		this->delayMarkAsset(Game::XAsset{ type, header });
	}

	unsigned short Zone::mapScriptString(unsigned short scriptString)
	{
		return 0xFFFF & this->scriptStringMap[scriptString];
	}

	void Zone::markScriptString(unsigned short scriptString)
	{
		if (this->scriptStringMap.find(scriptString) == this->scriptStringMap.end())
		{
			this->scriptStrings.push_back(Game::SL_ConvertToString(scriptString));
			this->scriptStringMap[scriptString] = this->scriptStrings.size();
		}
	}

	void Zone::addDependency(const std::string& zone)
	{
		if (std::find(this->dependencies.begin(), this->dependencies.end(), zone) == this->dependencies.end())
		{
			this->dependencies.push_back(zone);
		}
	}

	int Zone::getAssetIndex(void* pointer)
	{
		for (unsigned int i = 0; i < this->assets.size(); ++i)
		{
			if (this->assets[i].header.data == pointer)
			{
				return i;
			}
		}

		return -1;
	}

	size_t Zone::getAssetCount()
	{
		return this->assets.size();
	}

	void Zone::writeHeader(Stream& stream)
	{
		Game::ZoneHeader header;
		ZeroMemory(&header, sizeof(header));

		header.assetList.assetCount = this->assets.size();
		Stream::ResetPointer(header.assetList.assets);

		if (!this->dependencies.empty())
		{
			header.assetList.dependCount = this->dependencies.size();
			Stream::ResetPointer(header.assetList.depends);
		}

		if (!this->scriptStrings.empty())
		{
			header.assetList.stringList.count = this->scriptStrings.size() + 1; // 'nullptr' scriptstring included
			Stream::ResetPointer(header.assetList.stringList.strings);
		}

		stream.write(header);
	}

	void Zone::fixupHeader(Stream& stream)
	{
		auto& buffer = stream.getBuffer();

		XFile* header = reinterpret_cast<XFile*>(PCHAR(buffer.data()));
		header->size = buffer.size() - sizeof(XFile);
		header->externalSize = 0; // External data (e.g. images)

		for (int i = 0; i < MAX_XFILE_COUNT; i++)
		{
			header->blockSize[i] = stream.getBlockSize(i);
		}
	}

	void Zone::writeScriptStrings(Stream& stream)
	{
		if (this->scriptStrings.empty()) return;

		stream.align(3);
		stream.writeRVal(0ul); // 'nullptr' scriptstring

		for (unsigned int i = 0; i < this->scriptStrings.size(); ++i)
		{
			stream.writeRVal(-1l);
		}

		for (auto& string : this->scriptStrings)
		{
			stream.writeString(string);
		}
	}

	void Zone::writeDependencies(Stream& stream)
	{
		if (this->dependencies.empty()) return;

		stream.align(3);

		for (unsigned int i = 0; i < this->dependencies.size(); ++i)
		{
			stream.writeRVal(-1l);
		}

		for (auto& dependency : this->dependencies)
		{
			stream.writeString(dependency);
		}
	}

	void Zone::writeAssets(Stream& stream)
	{
		if (this->assets.empty()) return;

		stream.align(3);
		stream.setIndexStart(stream.getBlockSize(Game::XFILE_BLOCK_VIRTUAL));

		for (auto& asset : this->assets)
		{
			Game::XAsset entry;
			entry.type = asset.type;
			Stream::ResetPointer(entry.header.data);

			stream.write(entry);
		}

		stream.pushBlock(Game::XFILE_BLOCK_TEMP);

		for (auto& asset : this->assets)
		{
			Components::Linker::SaveAsset(&asset);
		}

		stream.popBlock();
	}

	FastFile Zone::build()
	{
		Stream stream(0xC800000);
		Components::Linker::LinkerLock _;
		Components::Linker::SetZone(this);
		Components::Linker::SetStream(&stream);
		Components::Linker::EnablePatches();

// 		auto test = this->assets;
// 		this->assets.clear();
// 		for (unsigned int i = 0; i < std::min(3u, test.size()); ++i)
// 		{
// 			this->assets.push_back(test[i]);
// 		}

		this->writeHeader(stream);

		stream.pushBlock(Game::XFILE_BLOCK_VIRTUAL);

		this->writeScriptStrings(stream);
		this->writeDependencies(stream);
		this->writeAssets(stream);
		this->fixupHeader(stream);

		stream.popBlock();

		Components::Linker::DisablePatches();
		Components::Linker::SetStream(nullptr);
		Components::Linker::SetZone(nullptr);

		return FastFile::Compress(stream.getBuffer());
	}
}
