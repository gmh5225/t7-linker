#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Game/Structs.hpp"

namespace Game
{
	typedef void(*Cbuf_AddText_t)(LocalClientNum_t localClientNum, const char *text);
	extern Cbuf_AddText_t Cbuf_AddText;

	typedef int(__cdecl * Cmd_Argc_t)();
	extern Cmd_Argc_t Cmd_Argc;

	typedef const char *(__cdecl * Cmd_Argv_t)(int argIndex);
	extern Cmd_Argv_t Cmd_Argv;

	typedef void(__cdecl * Cmd_ExecuteSingleCommand_t)(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text, bool fromRemoteConsole);
	extern Cmd_ExecuteSingleCommand_t Cmd_ExecuteSingleCommand;

	typedef void(*Com_AddStartupCommands_t)();
	extern Com_AddStartupCommands_t Com_AddStartupCommands;

	typedef int(*Com_HashKey_t)(const char* string, int maxlen);
	extern Com_HashKey_t Com_HashKey;

	typedef XAssetHeader(*DB_FindXAssetHeader_t)(XAssetType type, const char *name, bool errorIfMissing, int waitTime);
	extern DB_FindXAssetHeader_t DB_FindXAssetHeader;

	typedef const char *(*DB_GetXAssetTypeName_t)(int type);
	extern DB_GetXAssetTypeName_t DB_GetXAssetTypeName;

	typedef int(*DB_GetXAssetTypeSize_t)(int type);
	extern DB_GetXAssetTypeSize_t DB_GetXAssetTypeSize;

	typedef const char *(*DB_GetXAssetName_t)(XAsset *asset);
	extern DB_GetXAssetName_t DB_GetXAssetName;

	typedef void(*DB_SetXAssetName_t)(XAsset *asset, const char *name);
	extern DB_SetXAssetName_t DB_SetXAssetName;

	typedef void(*Load_XAssetHeader_t)(bool atStreamStart);
	extern Load_XAssetHeader_t Load_XAssetHeader;

	typedef void(*Mark_XAsset_t)();
	extern Mark_XAsset_t Mark_XAsset;

	typedef const char *(*SL_ConvertToString_t)(unsigned int stringValue);
	extern SL_ConvertToString_t SL_ConvertToString;

	typedef bool(*Sys_IsDatabaseReady_t)();
	extern Sys_IsDatabaseReady_t Sys_IsDatabaseReady;

	extern void** DB_XAssetPool;
	extern unsigned int* g_poolSize;

	extern XAsset*& varXAsset;
	extern XAssetHeader*& varXAssetHeader;

	extern cmd_function_s*& cmd_functions;

	extern const char** g_assetNames;

	void* ReallocateAssetPool(Game::XAssetType type, unsigned int newSize);
}
