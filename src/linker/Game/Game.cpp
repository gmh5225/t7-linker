#include "STDInclude.hpp"

#include "Game.hpp"

namespace Game
{
	Cbuf_AddText_t Cbuf_AddText = Cbuf_AddText_t(0x6B85A0);

	Cmd_ExecuteSingleCommand_t Cmd_ExecuteSingleCommand = Cmd_ExecuteSingleCommand_t(0x6B9ED0);
	Cmd_Argc_t Cmd_Argc = Cmd_Argc_t(0x42E3F0);
	Cmd_Argv_t Cmd_Argv = Cmd_Argv_t(0x42E470);

	Com_AddStartupCommands_t Com_AddStartupCommands = Com_AddStartupCommands_t(0x6C2B10);
	Com_HashKey_t Com_HashKey = Com_HashKey_t(0x772290);

	DB_FindXAssetHeader_t DB_FindXAssetHeader = DB_FindXAssetHeader_t(0x559810);
	DB_GetXAssetTypeName_t DB_GetXAssetTypeName = DB_GetXAssetTypeName_t(0x538B40);
	DB_GetXAssetTypeSize_t DB_GetXAssetTypeSize = DB_GetXAssetTypeSize_t(0x538B00);
	DB_GetXAssetName_t DB_GetXAssetName = DB_GetXAssetName_t(0x538A70);
	DB_SetXAssetName_t DB_SetXAssetName = DB_SetXAssetName_t(0x538AB0);

	Load_XAssetHeader_t Load_XAssetHeader = Load_XAssetHeader_t(0x550B10);

	Mark_XAsset_t Mark_XAsset = Mark_XAsset_t(0x54CDD0);

	SL_ConvertToString_t SL_ConvertToString = SL_ConvertToString_t(0x846680);

	Sys_IsDatabaseReady_t Sys_IsDatabaseReady = Sys_IsDatabaseReady_t(0x6E5E00);

	void** DB_XAssetPool = reinterpret_cast<void**>(0xDB7790);
	unsigned int* g_poolSize = reinterpret_cast<unsigned int*>(0xDB73D0);

	XAsset*& varXAsset = *reinterpret_cast<XAsset**>(0x137B9A0);
	XAssetHeader*& varXAssetHeader = *reinterpret_cast<XAssetHeader**>(0x137BAD8);

	cmd_function_s*& cmd_functions = *reinterpret_cast<cmd_function_s**>(0x1D8C514);

	const char** g_assetNames = reinterpret_cast<const char**>(0xDB6D00);

	void* ReallocateAssetPool(Game::XAssetType type, unsigned int newSize)
	{
		int elSize = DB_GetXAssetTypeSize(type);
		void* poolEntry = Utils::Memory::GetAllocator()->allocate(newSize * elSize);
		DB_XAssetPool[type] = poolEntry;
		g_poolSize[type] = newSize;
		return poolEntry;
	}
}
