#include "STDInclude.hpp"

#include "Game/Zone.hpp"

#include "Core/Components/Core.hpp"
#include "Core/Components/Command.hpp"
#include "Core/Components/Console.hpp"
#include "Core/Components/Scheduler.hpp"

#define ZONE_PATH "zone/pluto"

namespace Components
{
	Game::FastFile Core::BuildZone(std::string zoneName)
	{
		Utils::Memory::Allocator allocator;

		Utils::IO::File zoneSource("zone_source/" + zoneName + ".csv");
		auto data = zoneSource.read();
		if (!data.result)
		{
			Console::Error("No source found for zone '%s'\n", zoneName.data());
			return Game::FastFile();
		}

		Utils::CSV csv(data.data);
		Game::Zone zone;

		for (unsigned int i = 0; i < csv.getRowCount(); ++i)
		{
			auto& row = csv.getRow(i);

			if (row.getColumnCount() >= 2)
			{
				auto assetTypeName = row.getColumn(0);
				auto assetName = row.getColumn(1);
				auto newAssetName = row.getColumnCount() > 2 ? row.getColumn(2) : assetName;

				auto assetType = Game::ASSET_TYPE_INVALID;
				for (int j = 0; j < Game::ASSET_TYPE_FULL_COUNT; ++j)
				{
					if (assetTypeName == Game::g_assetNames[j])
					{
						assetType = Game::XAssetType(j);
						break;
					}
				}

				if (assetType == Game::ASSET_TYPE_INVALID)
				{
					Console::Error("Invalid asset type '%s'\n", assetTypeName.data());
					return Game::FastFile();
				}

				auto assetHeader = Game::DB_FindXAssetHeader(assetType, assetName.data(), true, -1);

				if (newAssetName != assetName)
				{
					Game::XAsset asset;
					asset.type = assetType;
					asset.header = assetHeader;

					auto oldName = Game::DB_GetXAssetName(&asset);
					Game::DB_SetXAssetName(&asset, allocator.duplicateString(newAssetName));

					allocator.reference(assetHeader.data, [assetType, oldName](void* header)
					{
						Game::XAsset asset;
						asset.type = assetType;
						asset.header.data = header;

						Game::DB_SetXAssetName(&asset, oldName);
					});
				}

				zone.addAsset(assetType, assetHeader);
			}
		}

		return zone.build();
	}

	void Core::Initialize()
	{
		if (!Game::Sys_IsDatabaseReady())
		{
			Scheduler::Once(Core::Initialize);
			return;
		}

		Game::Com_AddStartupCommands();

		// Quit the linker after all commands are executed
		Scheduler::OnDelay([]() { Command::Execute("quit"); }, 1s, true);
	}

	Core::Core()
	{
		const char* zonepath = "default";
		Utils::Hook::Set(0x5549DB, zonepath); // DB_TryLoadXFileInternal
		Utils::Hook::Set(0x55446A, zonepath); // DB_BuildOSPath_FromSource

		// Fix startup routine
		Utils::Hook::Nop(0x692FD2, 5); // LiveSteam_Init
		Utils::Hook::Nop(0x6C338B, 5); // Com_ClientPacketEvent
		Utils::Hook::Nop(0x6C68BE, 5); // Com_GametypeSettings_Init
		Utils::Hook::Nop(0x6C68DF, 5); // Live_Init
		Utils::Hook::Nop(0x6C6912, 5); // Content_Init
		Utils::Hook::Nop(0x6C6D6A, 5); // NET_Init
		Utils::Hook::Nop(0x6C6DCE, 5); // SV_InitServerThread
		Utils::Hook::Nop(0x6F5A8B, 5); // LiveSteam_Server_Init
		Utils::Hook::Nop(0x7A119C, 5); // Live_Base_Init
		Utils::Hook::Nop(0x7A1062, 5); // DedicatedInit
		Utils::Hook::Nop(0x6F4B0E, 5); // SV_StatSign_Init
		Utils::Hook::Nop(0x6C4FD1, 5); // LiveSteam_Frame

		// Block DW connection 
		Utils::Hook::Set<BYTE>(0x564990, 0xC3);        // dwNetPump
		Utils::Hook::Set<BYTE>(0x693CA0, 0xC3);        // Live_Base_Pump
		Utils::Hook::Set<BYTE>(0x693BB0, 0xC3);        // Live_Base_PumpForController
		Utils::Hook::Set<DWORD>(0x692B70, 0x90C301B0); // Live_Base_AuthorizeLicenseWithDW

		// Ignore overridden assets
		Utils::Hook::Nop(0x553EBA, 5);

		// Block command registration
		Utils::Hook::Set<BYTE>(0x6B94F0, 0xC3);
		Utils::Hook::Set<BYTE>(0x6B9600, 0xC3);

		Utils::Hook::Set<BYTE>(0x7A0870, 0xC3); // Remove command line check
		Utils::Hook::Set<BYTE>(0x6C4DDF, 0xEB); // No Hitch warnings
		Utils::Hook::Set<BYTE>(0x5587CB, 0xEB); // Ignore redundant assets
		Utils::Hook::Set<BYTE>(0x70A75D, 0xEB); // Ignore missing language files
		Utils::Hook::Set<BYTE>(0x6C6FD6, 0xEB); // Don't execute startup commands here

		// Block asset loading
		Utils::Hook::Nop(0x53C0BF, 5);          // block loading of sounds
		Utils::Hook::Nop(0x8C76A0, 5);          // block loading of sounds
		Utils::Hook::Nop(0x55741C, 5);          // block loading of sounds
		Utils::Hook::Nop(0x53ECC1, 5);          // block loading of vertex shaders to preserve loadDef struct
		Utils::Hook::Nop(0x53ED41, 5);          // block loading of pixel shaders to preserve loadDef struct
		Utils::Hook::Nop(0x53F29E, 5);          // block loading of state bits to preserve loadDef struct
		Utils::Hook::Set<BYTE>(0x55A840, 0xC3); // block loading of FXs to preserve the name
		Utils::Hook::Set<BYTE>(0xA3BC00, 0xC3); // block loading of vertex declarations to preserve loadDef struct
		Utils::Hook::Set<BYTE>(0xA32DDB, 0);    // Set r_loadForRenderer = 0 - Block DX allocations

		Utils::Hook::Set<const char*>(0x75F82B, "data"); // fs_basegame

		// Allocate more memory
		Utils::Hook::Set<DWORD>(0x792BE6, 0x28000000);
		Utils::Hook::Set<DWORD>(0x792C00, 0x28000000);

		Game::ReallocateAssetPool(Game::ASSET_TYPE_FONT, 32);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_XANIMPARTS, 10400);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_WEAPON, 512);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_IMAGE, 10496);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_MATERIAL, 9472);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_FX, 1200);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_WEAPON_CAMO, 256);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_XMODEL, 2800);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_SNDDRIVER_GLOBALS, 5);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_RAWFILE, 2048);
		//Game::ReallocateAssetPool(ASSET_TYPE_DDL, 48);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_STRINGTABLE, 192);
		Game::ReallocateAssetPool(Game::ASSET_TYPE_LEADERBOARD, 256);

		Scheduler::Once(Core::Initialize);

		Command::Add("build", [](Command::Params params)
		{
			if (params.size() < 2) return;

			std::string zoneName = params[1];
			Game::FastFile fastFile = Core::BuildZone(zoneName);
			if (!fastFile.isValid()) return;
			
			Utils::IO::File file(ZONE_PATH "/decrypted/" + zoneName + ".ff");
			file.write(fastFile);

			Console::Info("FastFile '%s' written\n", file.getName().data());
		});

		Command::Add("encrypt", [](Command::Params params)
		{
			if (params.size() < 2) return;

			std::string zoneName = params[1];
			Utils::IO::File fastFile(ZONE_PATH "/decrypted/" + zoneName + ".ff");
			if (!fastFile.exists())
			{
				Console::Error("FastFile '%s' doesn't exist\n", zoneName.data());
				return;
			}

			Game::FastFile ff(fastFile);
			if (!ff.isValid())
			{
				Console::Error("FastFile '%s' is invalid\n", zoneName.data());
				return;
			}

			Utils::IO::File file(ZONE_PATH "/encrypted/" + zoneName + ".ff");
			file.write(ff.encrypt(zoneName));

			Console::Info("FastFile '%s' written\n", file.getName().data());
		});

		Command::Add("decrypt", [](Command::Params params)
		{
			if (params.size() < 2) return;

			std::string zoneName = params[1];
			Utils::IO::File fastFile(ZONE_PATH "/encrypted/" + zoneName + ".ff");
			if (!fastFile.exists())
			{
				Console::Error("FastFile '%s' doesn't exist\n", zoneName.data());
				return;
			}

			Game::FastFile ff(fastFile);
			if (!ff.isValid())
			{
				Console::Error("FastFile '%s' is invalid\n", zoneName.data());
				return;
			}

			Utils::IO::File file(ZONE_PATH "/decrypted/" + zoneName + ".ff");
			file.write(ff.decrypt());

			Console::Info("FastFile '%s' written\n", file.getName().data());
		});

		Command::Add("decompress", [](Command::Params params)
		{
			if (params.size() < 2) return;

			std::string zoneName = params[1];
			Utils::IO::File fastFile(ZONE_PATH "/encrypted/" + zoneName + ".ff");
			if (!fastFile.exists())
			{
				fastFile = Utils::IO::File(ZONE_PATH "/decrypted/" + zoneName + ".ff");
				if (!fastFile.exists())
				{
					Console::Error("FastFile '%s' doesn't exist\n", zoneName.data());
					return;
				}
			}

			Game::FastFile ff(fastFile);
			if (!ff.isValid())
			{
				Console::Error("FastFile '%s' is invalid\n", zoneName.data());
				return;
			}

			Utils::IO::File file(ZONE_PATH "/decompressed/" + zoneName + ".zone");
			file.write(ff.decompress());

			Console::Info("Zone '%s' written\n", file.getName().data());
		});

		Command::Add("compress", [](Command::Params params)
		{
			if (params.size() < 2) return;

			std::string zoneName = params[1];
			auto data = Utils::IO::File(ZONE_PATH "/decompressed/" + zoneName + ".zone").read();
			if (!data.result)
			{
				Console::Error("Zone '%s' doesn't exist\n", zoneName.data());
				return;
			}

			Game::FastFile ff = Game::FastFile::Compress(data.data);
			Utils::IO::File file(ZONE_PATH "/decrypted/" + zoneName + ".zone");
			file.write(ff);

			Console::Info("FastFile '%s' written\n", file.getName().data());
		});
	}
}
