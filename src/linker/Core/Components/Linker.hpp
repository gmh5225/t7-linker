#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Game/Zone.hpp"

#include "Core/Component.hpp"

namespace Components
{
	class Linker : public IComponent
	{
	public:
		class LinkerLock
		{
		public:
			LinkerLock() : lock(Linker::Mutex) {}

		private:
			std::lock_guard<std::recursive_mutex> lock;
		};

		Linker();

		static void EnablePatches();
		static void DisablePatches();

		static void SetStream(Game::Stream* stream);
		static void SetZone(Game::Zone* zone);

		static void SaveAsset(Game::XAsset* asset);
		static void DelayMarkAsset(Game::XAsset* asset);

	private:
		static std::recursive_mutex Mutex;

		static std::map<void*, void*> BranchMap;
		static std::map<void*, std::pair<DWORD, DWORD>>  AllocationMap;

		static std::map<Game::XAssetType, std::function<void(Game::XAsset*)>> AssetMarkers;

		static std::map<Game::XAssetType, std::pair<size_t, size_t>> AssetLoaders;
		static std::map<void*, DWORD> AssetStorage;

		static Utils::Hook OffsetToPointerHook;

		static Game::Stream* CurrentStream;
		static Game::Zone* CurrentZone;

		static bool IsWriting();
		static bool IsMarking();

		static std::function<bool(bool, void*, size_t)> Load_Stream;
		static bool Load_StreamHook(bool atStreamStart, void * pointer, size_t size);

		static std::function<void(const char **)> Load_XStringCustom;
		static void Load_XStringCustomHook(const char **str);

		static std::function<void(unsigned __int16 *)> Load_ScriptStringCustom;
		static void Load_ScriptStringCustomHook(unsigned __int16 *var);

		static void Image_ReleaseHook(Game::GfxImage *image);
		static void Load_TextureHook(Game::GfxImageLoadDef **remoteLoadDef, Game::GfxImage *image);

		static std::function<void(int)> DB_PushStreamPos;
		static void DB_PushStreamPosHook(int stream);

		static std::function<void()> DB_PopStreamPos;
		static void DB_PopStreamPosHook();

		static std::function<char*(int)> DB_AllocStreamPos;
		static char * DB_AllocStreamPosHook(int alignment);

		static void* DB_GetXAssetFunc;
		static void DB_GetXAsset(Game::XAssetType type, Game::XAssetHeader header);
		static void DB_GetXAssetHook(Game::XAssetType type, Game::XAssetHeader header);
		static void DB_GetXAssetStub();

		static std::function<void(unsigned __int16 *var)> Mark_ScriptStringCustom;
		static void Mark_ScriptStringCustomHook(unsigned __int16 *var);

		static void MapOffsetToPointerBranches(unsigned char* address);
		static bool IsOffsetToPointerBranch(unsigned char* address);

		static void MapStreamAllocation(unsigned char* address);

		static void* GetComplementaryBranch(char* branch);
		static bool CheckOffsetToPointerConversion(void** pointer);
		static void OffsetToPointerStub();

		static void BuildAssetLoader(int type, unsigned char* branch);
		static void BuildAssetLoaders();
	};
}
