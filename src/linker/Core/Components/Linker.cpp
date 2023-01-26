#include "STDInclude.hpp"

#include "Game/Game.hpp"

#include "Core/Components/Linker.hpp"

namespace Components
{
	std::recursive_mutex Linker::Mutex;

	std::map<void*, void*> Linker::BranchMap;
	std::map<void*, std::pair<DWORD, DWORD>> Linker::AllocationMap;

	std::map<Game::XAssetType, std::pair<size_t, size_t>> Linker::AssetLoaders;
	std::map<Game::XAssetType, std::function<void(Game::XAsset*)>> Linker::AssetMarkers;

	std::map<void*, DWORD> Linker::AssetStorage;

	Utils::Hook Linker::OffsetToPointerHook;

	Game::Zone* Linker::CurrentZone = nullptr;
	Game::Stream* Linker::CurrentStream = nullptr;

	bool Linker::IsWriting()
	{
		return Linker::CurrentStream;
	}

	bool Linker::IsMarking()
	{
		return Linker::CurrentZone;
	}

	void Linker::SetStream(Game::Stream* stream)
	{
		Linker::LinkerLock _;
		Linker::CurrentStream = stream;
	}

	void Linker::SetZone(Game::Zone* zone)
	{
		Linker::LinkerLock _;
		Linker::CurrentZone = zone;
	}

	void Linker::DelayMarkAsset(Game::XAsset* asset)
	{
		Linker::LinkerLock _;
		if (Linker::IsMarking())
		{
			auto handler = Linker::AssetMarkers.find(asset->type);
			if (handler != Linker::AssetMarkers.end())
			{
				handler->second(asset);
			}
		}
	}

	void Linker::SaveAsset(Game::XAsset* asset)
	{
		Linker::LinkerLock _;

		auto handler = Linker::AssetLoaders.find(asset->type);
		if (handler != Linker::AssetLoaders.end())
		{
			*reinterpret_cast<Game::XAssetHeader*>(handler->second.second) = asset->header;
			Utils::Hook::Call<void(bool)>(handler->second.first)(true);
		}
	}

	std::function < bool(bool atStreamStart, void* pointer, size_t size) > Linker::Load_Stream;
	bool Linker::Load_StreamHook(bool atStreamStart, void* pointer, size_t size)
	{
		if (Linker::IsWriting() && Linker::CurrentZone)
		{
			if (!atStreamStart && size == 4 && _ReturnAddress() != PVOID(0x5450A4)) // Is either an offset, or an alias, or a structure that has 4 bytes and not the texture loaddef shit
			{
				int assetIndex = Linker::CurrentZone->getAssetIndex(*reinterpret_cast<void**>(pointer));
				if (assetIndex != -1)
				{
					Game::Stream::Offset offset;
					offset.stream = Game::XFILE_BLOCK_VIRTUAL;
					offset.value = (Linker::CurrentStream->getIndexStart() + (assetIndex * sizeof(Game::XAsset)) + /*offsetof(Game::XAsset, header)*/ 4);

					void* ptr = Linker::CurrentStream->findPointer(pointer);
					*PDWORD(ptr) = offset.getPackedValue();
				}
			}
			else if (atStreamStart)
			{
				Linker::CurrentStream->storePointer(pointer, size);
				Linker::CurrentStream->write(pointer, size);
			}

			return true;
		}
		else
		{
			return Load_Stream(atStreamStart, pointer, size);
		}
	}

	std::function<void(const char **)> Linker::Load_XStringCustom;
	void Linker::Load_XStringCustomHook(const char **str)
	{
		if (Linker::IsWriting())
		{
			Linker::CurrentStream->writeString(*str);
		}
		else
		{
			return Linker::Load_XStringCustom(str);
		}
	}

	std::function<void(unsigned __int16 *)> Linker::Load_ScriptStringCustom;
	void Linker::Load_ScriptStringCustomHook(unsigned __int16 *var)
	{
		if (Linker::IsWriting() && Linker::CurrentZone)
		{
			auto scriptString = Linker::CurrentZone->mapScriptString(*var);
			void* ptr = Linker::CurrentStream->findPointer(var);
			*PWORD(ptr) = scriptString;
		}
		else
		{
			return Linker::Load_ScriptStringCustom(var);
		}
	}

	void Linker::Image_ReleaseHook(Game::GfxImage *image)
	{
		Utils::Memory::GetAllocator()->free(image->texture.loadDef);
	}

	void Linker::Load_TextureHook(Game::GfxImageLoadDef **remoteLoadDef, Game::GfxImage* image)
	{
		if (!Linker::IsWriting())
		{
			auto loadDef = reinterpret_cast<Game::GfxImageLoadDef*>(Utils::Memory::GetAllocator()->allocate(12 + (*remoteLoadDef)->resourceSize));
			std::memcpy(loadDef, *remoteLoadDef, 12 + (*remoteLoadDef)->resourceSize);
			*remoteLoadDef = loadDef;
			image->texture.loadDef = loadDef;
		}
		else
		{
			void* ptr = Linker::CurrentStream->findPointer(remoteLoadDef);
			*PINT(ptr) = -1;
		}
	}

	std::function < void(int) > Linker::DB_PushStreamPos;
	void Linker::DB_PushStreamPosHook(int stream)
	{
		if (Linker::IsWriting())
		{
			Linker::CurrentStream->pushBlock(stream);
		}
		else
		{
			return Linker::DB_PushStreamPos(stream);
		}
	}

	std::function < void() > Linker::DB_PopStreamPos;
	void Linker::DB_PopStreamPosHook()
	{
		if (Linker::IsWriting())
		{
			Linker::CurrentStream->popBlock();
		}
		else
		{
			return Linker::DB_PopStreamPos();
		}
	}

	std::function < char*(int) > Linker::DB_AllocStreamPos;
	char* Linker::DB_AllocStreamPosHook(int alignment)
	{
		if (Linker::IsWriting())
		{
			Linker::CurrentStream->align(alignment);
			return nullptr;
		}
		else
		{
			return Linker::DB_AllocStreamPos(alignment);
		}
	}

	void* Linker::DB_GetXAssetFunc;
	__declspec(naked) void Linker::DB_GetXAsset(Game::XAssetType /*type*/, Game::XAssetHeader /*header*/)
	{
		__asm
		{
			mov edi, [esp + 4h]
			push[esp + 8h]
			call Linker::DB_GetXAssetFunc
			add esp, 4h
			retn
		}
	}

	__declspec(naked) void Linker::DB_GetXAssetStub()
	{
		__asm
		{
			push[esp + 4h]
			push edi
			call Linker::DB_GetXAssetHook
			add esp, 8h
			retn
		}
	}

	void Linker::DB_GetXAssetHook(Game::XAssetType type, Game::XAssetHeader header)
	{
		if (Linker::IsMarking())
		{
			Linker::CurrentZone->markAsset({ type,header });
		}
		else
		{
			return Linker::DB_GetXAsset(type, header);
		}
	}

	std::function<void(unsigned __int16 *var)> Linker::Mark_ScriptStringCustom;
	void Linker::Mark_ScriptStringCustomHook(unsigned __int16 *var)
	{
		if (Linker::IsMarking())
		{
			if (var && *var)
			{
				Linker::CurrentZone->markScriptString(*var);
			}
		}
		else
		{
			return Linker::Mark_ScriptStringCustom(var);
		}
	}

	bool Linker::IsOffsetToPointerBranch(unsigned char* address)
	{
		if (::Utils::Memory::IsBadCodePtr(address)) return false;

		ud_t ud;
		ud_init(&ud);
		ud_set_mode(&ud, 32);
		ud_set_pc(&ud, uint64_t(address));
		ud_set_input_buffer(&ud, (unsigned char*)address, INT32_MAX);

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Ipush) return false;

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Icall) return false;

		auto operand = ud_insn_opr(&ud, 0);
		if (operand->type != UD_OP_JIMM || operand->size != 32) return false;

		DWORD offset = operand->lval.udword;

		void* tFunction = PCHAR(ud_insn_off(&ud) + ud_insn_len(&ud) + offset);
		return tFunction == PVOID(0x55AF00); // DB_ConvertOffsetToPointer
	}

	void Linker::MapOffsetToPointerBranches(unsigned char* address)
	{
		if (::Utils::Memory::IsBadCodePtr(address)) return;

		ud_t ud;
		ud_init(&ud);
		ud_set_mode(&ud, 32);
		ud_set_pc(&ud, uint64_t(address));
		ud_set_input_buffer(&ud, address, INT32_MAX);

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Icmp) return;

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Ijnz) return;

		auto operand = ud_insn_opr(&ud, 0);
		if (operand->type != UD_OP_JIMM || operand->size != 8) return;

		DWORD offset = operand->lval.ubyte;
		unsigned char* writeBranch = PUCHAR(ud_insn_off(&ud) + ud_insn_len(&ud));
		unsigned char* offsetBranch = writeBranch + offset;

		if (!Linker::IsOffsetToPointerBranch(offsetBranch)) return;

		Linker::BranchMap[offsetBranch] = writeBranch;
	}

	void* Linker::GetComplementaryBranch(char* branch)
	{
		auto branches = Linker::BranchMap.find(branch - 6);
		if (branches != Linker::BranchMap.end())
		{
			return branches->second;
		}

		MessageBoxA(0, "Unable to locate complementary branch", "ERROR", MB_ICONERROR);
		return branch + 3;
	}

	bool Linker::CheckOffsetToPointerConversion(void** pointer)
	{
		void* ptr = Linker::CurrentStream->findPointer(pointer);
		if (Linker::CurrentStream->hasPointer(*pointer))
		{
			*PINT(ptr) = Linker::CurrentStream->safeGetPointer(*pointer);
			return true;
		}
		else
		{
			*PINT(ptr) = -1;
			return false;
		}
	}

	__declspec(naked) void Linker::OffsetToPointerStub()
	{
		__asm
		{
			pushad
			push [esp + 24h]
			call Linker::CheckOffsetToPointerConversion
			add esp, 4h

			test al, al
			jz returnComplementaryBranch

			popad
			retn

		returnComplementaryBranch:
			push [esp + 20h]
			call Linker::GetComplementaryBranch
			add esp, 4h

			mov [esp + 24h], eax
			popad
			add esp, 4h
			retn
		}
	}

	void Linker::MapStreamAllocation(unsigned char* address)
	{
		unsigned char* callOperation = address; //address + 2 + (*address == 0x68 ? 3 : 0);
		unsigned long functionOffset = *PDWORD(callOperation + 1);
		unsigned char* function = callOperation + functionOffset + 5;
		unsigned char* target = callOperation + 11;

		if (function != PUCHAR(0x55ABD0)) return;

		ud_t ud;
		ud_init(&ud);
		ud_set_mode(&ud, 32);
		ud_set_pc(&ud, uint64_t(target));
		ud_set_input_buffer(&ud, target, INT32_MAX);
		ud_disassemble(&ud);

		Linker::AllocationMap[target] = { *PDWORD(target), ud_insn_len(&ud) };
	}

	void Linker::EnablePatches()
	{
		Linker::LinkerLock _;

		for (auto& entry : Linker::AllocationMap)
		{
			Utils::Hook::Nop(entry.first, entry.second.second);
		}

		for (auto& entry : Linker::AssetStorage)
		{
			Utils::Hook::Nop(entry.first, 5);
		}

		// Block DB_ConvertOffsetToAlias
		Utils::Hook::Set<BYTE>(0x55AEA0, 0xC3);

		// Block Assert_MyHandler
		Utils::Hook::Set<DWORD>(0x745150, 0xC301B0);

		// Block loading texture loaddefs as aliases
		Utils::Hook::Set<BYTE>(0x5450CD, 0xEB);
		Utils::Hook::Set<BYTE>(0x545101, 0xEB);

		Linker::OffsetToPointerHook.install();
	}

	void Linker::DisablePatches()
	{
		Linker::LinkerLock _;

		Linker::OffsetToPointerHook.uninstall();

		// Restore DB_ConvertOffsetToAlias
		Utils::Hook::Set<BYTE>(0x55AEA0, 0x55);

		// Restore Assert_MyHandler
		Utils::Hook::Set<DWORD>(0x745150, 0x51EC8B55);

		// Restore loading texture loaddefs as aliases
		Utils::Hook::Set<BYTE>(0x5450CD, 0x74);
		Utils::Hook::Set<BYTE>(0x545101, 0x75);

		for (auto& entry : Linker::AssetStorage)
		{
			Utils::Hook::Set<DWORD>(entry.first, 0xEB);
			Utils::Hook::Set<DWORD>(PCHAR(entry.first) + 1, entry.second);
		}

		for (auto& entry : Linker::AllocationMap)
		{
			Utils::Hook::Set<DWORD>(entry.first, entry.second.first);
		}
	}

	void Linker::BuildAssetLoader(int type, unsigned char* branch)
	{
		unsigned char* operation = branch + 11;
		if (*operation != 0xE9)
		{
			operation += 2;
			if (*operation != 0xE9) return;
		}

		unsigned char* loader = operation + 5 + *PDWORD(operation + 1);

		ud_t ud;
		ud_init(&ud);
		ud_set_mode(&ud, 32);
		ud_set_pc(&ud, uint64_t(loader));
		ud_set_input_buffer(&ud, loader, INT32_MAX);

		// This might be potentially dangerous as we skip jumps and rely on
		// continuous operations in memory neglecting alignments and such.
		uint64_t target = 0;
		while (true)
		{
			ud_disassemble(&ud);
			if (ud_insn_mnemonic(&ud) != UD_Ijmp) continue;

			auto operand = ud_insn_opr(&ud, 0);
			if (operand->type != UD_OP_JIMM || operand->size != 8) continue;

			target = ud_insn_off(&ud) + ud_insn_len(&ud) + operand->lval.sbyte;
			break;
		}

		ud_set_pc(&ud, target);
		ud_set_input_buffer(&ud, PUCHAR(target), INT32_MAX);

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Ipush) return;

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Icall) return;

		auto operand = ud_insn_opr(&ud, 0);
		if (operand->type != UD_OP_JIMM || operand->size != 32) return;

		target = ud_insn_off(&ud) + ud_insn_len(&ud) + operand->lval.sdword;
		DWORD var = *PDWORD(target + 4);

		Linker::AssetLoaders[Game::XAssetType(type)] = { target, var };

		// Just patch the asset storage functions if we're already there
		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Imov) return;

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Ipush) return;

		ud_disassemble(&ud);
		if (ud_insn_mnemonic(&ud) != UD_Icall) return;

		auto pointer = PCHAR(ud_insn_off(&ud));
		Linker::AssetStorage[pointer] = *PDWORD(pointer + 1);
	}

	void Linker::BuildAssetLoaders()
	{
		ud_t ud;
		ud_init(&ud);
		ud_set_mode(&ud, 32);
		ud_set_pc(&ud, uint64_t(Game::Load_XAssetHeader));
		ud_set_input_buffer(&ud, PUCHAR(Game::Load_XAssetHeader), INT32_MAX);

		while (true)
		{
			ud_disassemble(&ud);
			if (ud_insn_mnemonic(&ud) == UD_Iret || ud_insn_mnemonic(&ud) == UD_Ijmp) break;
			if (ud_insn_mnemonic(&ud) != UD_Icmp) continue;

			auto operand = ud_insn_opr(&ud, 1);
			if (operand->type != UD_OP_IMM || operand->size != 8) continue;

			int assetType = operand->lval.ubyte;

			ud_disassemble(&ud);
			if (ud_insn_mnemonic(&ud) == UD_Iret || ud_insn_mnemonic(&ud) == UD_Ijmp) break;

			if (assetType == Game::ASSET_TYPE_CLIPMAP || assetType == Game::ASSET_TYPE_CLIPMAP_PVS)
			{
				if (ud_insn_mnemonic(&ud) != UD_Ijz) continue;

				operand = ud_insn_opr(&ud, 0);
				if (operand->type != UD_OP_JIMM || operand->size != 32) continue;

				Linker::BuildAssetLoader(assetType, PUCHAR(ud_insn_off(&ud) + ud_insn_len(&ud) + operand->lval.sdword));
				continue;
			}

			if (ud_insn_mnemonic(&ud) != UD_Ijnz) continue;

			operand = ud_insn_opr(&ud, 0);
			if (operand->type != UD_OP_JIMM || operand->size != 8) continue;

			uint64_t loadBranch = ud_insn_off(&ud) + ud_insn_len(&ud);
			uint64_t continueBranch = loadBranch + operand->lval.sbyte;

			Linker::BuildAssetLoader(assetType, PUCHAR(loadBranch));

			ud_set_pc(&ud, continueBranch);
			ud_set_input_buffer(&ud, PUCHAR(continueBranch), INT32_MAX);
		}
	}

	Linker::Linker()
	{
		Linker::BranchMap.clear();
		Linker::AllocationMap.clear();

		Utils::NT::Module proc;
		Utils::Hook::Signature signature(proc.getCodeStart(), proc.getCodeSize());
		signature.add({ "\x83?\xFF\x75", "x?xx", Linker::MapOffsetToPointerBranches }); // Matches cmp eax, -1; jnz ...
		//signature.add({ "\x6A?\xE8", "x?x", Linker::MapStreamAllocation }); // Matches push ...; call ...
		//signature.add({ "\x68????\xE8", "x????x", Linker::MapStreamAllocation }); // Matches push ...; call ...
		signature.add({ "\xE8", "x", Linker::MapStreamAllocation });
		signature.process();

		// Various hooks required to write data properly
		Utils::Hook::Detour xAssetHook(true);
		xAssetHook.create(LPVOID(0x554330), Linker::DB_GetXAssetStub);
		Linker::DB_GetXAssetFunc = xAssetHook.get<void*>();

		Linker::Mark_ScriptStringCustom = Utils::Hook::Detour::Static(0x55AFB0, Linker::Mark_ScriptStringCustomHook);

		Linker::Load_Stream = Utils::Hook::Detour::Static(0x55AD00, Linker::Load_StreamHook);
		Linker::Load_XStringCustom = Utils::Hook::Detour::Static(0x55AF30, Linker::Load_XStringCustomHook);
		Linker::Load_ScriptStringCustom = Utils::Hook::Detour::Static(0x55AF90, Linker::Load_ScriptStringCustomHook);
		Linker::DB_PushStreamPos = Utils::Hook::Detour::Static(0x55AA50, Linker::DB_PushStreamPosHook);
		Linker::DB_PopStreamPos = Utils::Hook::Detour::Static(0x55AB30, Linker::DB_PopStreamPosHook);
		Linker::DB_AllocStreamPos = Utils::Hook::Detour::Static(0x55ABD0, Linker::DB_AllocStreamPosHook);

		Utils::Hook(0xA730A0, Linker::Image_ReleaseHook, HOOK_JUMP).install()->quick();
		Utils::Hook(0x545122, Linker::Load_TextureHook, HOOK_CALL).install()->quick();

		Linker::OffsetToPointerHook.initialize(0x55AF00, Linker::OffsetToPointerStub);

		Linker::BuildAssetLoaders();

		Linker::AssetMarkers[Game::ASSET_TYPE_ATTACHMENT_UNIQUE] = [](Game::XAsset* asset)
		{
			if (asset->header.attachmentUnique->szAltWeaponName && asset->header.attachmentUnique->szAltWeaponName[0])
			{
				Game::XAsset newAsset;
				newAsset.type = Game::ASSET_TYPE_WEAPON;
				newAsset.header = Game::DB_FindXAssetHeader(newAsset.type, asset->header.attachmentUnique->szAltWeaponName, true, -1);
				Linker::CurrentZone->delayMarkAsset(newAsset);
			}
		};

		Linker::AssetMarkers[Game::ASSET_TYPE_FX] = [](Game::XAsset* asset)
		{
			auto fx = asset->header.fx;
			if (fx->elemDefs)
			{
				for (int i = 0; i < fx->elemDefCountLooping + fx->elemDefCountOneShot + fx->elemDefCountEmission; ++i)
				{
					auto elemDef = &fx->elemDefs[i];

					static auto markFxRef = [] (Game::FxEffectDefRef ref)
					{
						if (!ref.name || !ref.name[0]) return;

						Game::XAsset newAsset;
						newAsset.type = Game::ASSET_TYPE_FX;
						newAsset.header = Game::DB_FindXAssetHeader(newAsset.type, ref.name, true, -1);
						Linker::CurrentZone->delayMarkAsset(newAsset);
					};

					static auto markFxVisuals = [](Game::FxElemVisuals* visuals, int type)
					{
						if (type == 12)
						{
							markFxRef(visuals->effectDef);
						}
						else if (type == 10)
						{
// 							Game::XAsset newAsset;
// 							newAsset.type = Game::ASSET_TYPE_SOUND;
// 							newAsset.header = Game::DB_FindXAssetHeader(newAsset.type, visuals->soundName, true, -1);
// 							Linker::CurrentZone->delayMarkAsset(newAsset);
						}
					};

					markFxRef(elemDef->effectOnImpact);
					markFxRef(elemDef->effectOnDeath);
					markFxRef(elemDef->effectEmitted);
					markFxRef(elemDef->effectAttached);

					if (elemDef->elemType != 11)
					{
						if (elemDef->visualCount > 1)
						{
							for (char j = 0; j < elemDef->visualCount; ++j)
							{
								markFxVisuals(&elemDef->visuals.array[j], elemDef->elemType);
							}
						}
						else
						{
							markFxVisuals(&elemDef->visuals.instance, elemDef->elemType);
						}
					}
				}
			}
		};

		Linker::AssetMarkers[Game::ASSET_TYPE_WEAPON] = [](Game::XAsset* asset)
		{
			if (asset->header.weapon->szXAnims)
			{
				for (int i = 0; i < 88; ++i)
				{
					auto anim = asset->header.weapon->szXAnims[i];
					if (anim && *anim)
					{
						Game::XAsset newAsset;
						newAsset.type = Game::ASSET_TYPE_XANIMPARTS;
						newAsset.header = Game::DB_FindXAssetHeader(newAsset.type, anim, true, -1);
						Linker::CurrentZone->delayMarkAsset(newAsset);
					}
				}
			}

			//asset->header.weapon->weapDef->parentWeaponName = "\0";
		};
	}
}
