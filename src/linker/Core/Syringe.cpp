#include "STDInclude.hpp"

#include <winnt.h>
#include "Core/Syringe.hpp"

namespace Core
{
	Syringe::Syringe(const std::string& _data) : data(_data) {}

	void Syringe::loadSection(Utils::NT::Module target, Utils::NT::Module source, IMAGE_SECTION_HEADER* section)
	{
		void* targetPtr = target.getPtr() + section->VirtualAddress;
		const void* sourcePtr = source.getPtr() + section->PointerToRawData;

		if (PBYTE(targetPtr) >= (target.getPtr() + BINARY_PAYLOAD_SIZE))
		{
			MessageBoxA(nullptr, "Section exceeds the binary payload size, please increase it!", nullptr, MB_ICONERROR);
			TerminateProcess(GetCurrentProcess(), 1);
		}

		if (section->SizeOfRawData > 0)
		{
			DWORD sizeOfData = std::min(section->SizeOfRawData, section->Misc.VirtualSize);
			std::memmove(targetPtr, sourcePtr, sizeOfData);

			DWORD oldProtect;
			VirtualProtect(targetPtr, sizeOfData, PAGE_EXECUTE_READWRITE, &oldProtect);
		}
	}

	void Syringe::loadSections(Utils::NT::Module target, Utils::NT::Module source)
	{
		for (auto& section : source.getSectionHeaders())
		{
			this->loadSection(target, source, section);
		}
	}

	void Syringe::loadImports(Utils::NT::Module target, Utils::NT::Module source)
	{
		IMAGE_DATA_DIRECTORY* importDirectory = &source.getOptionalHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];

		auto descriptor = PIMAGE_IMPORT_DESCRIPTOR(target.getPtr() + importDirectory->VirtualAddress);

		while (descriptor->Name)
		{
			std::string name = LPSTR(target.getPtr() + descriptor->Name);

			auto nameTableEntry = reinterpret_cast<uintptr_t*>(target.getPtr() + descriptor->OriginalFirstThunk);
			auto addressTableEntry = reinterpret_cast<uintptr_t*>(target.getPtr() + descriptor->FirstThunk);

			// GameShield (Payne) uses FirstThunk for original name addresses
			if (!descriptor->OriginalFirstThunk)
			{
				nameTableEntry = reinterpret_cast<uintptr_t*>(target.getPtr() + descriptor->FirstThunk);
			}

			while (*nameTableEntry)
			{
				FARPROC function = nullptr;
				std::string functionName;

				// is this an ordinal-only import?
				if (IMAGE_SNAP_BY_ORDINAL(*nameTableEntry))
				{
					Utils::NT::Module module = Utils::NT::Module::Load(name);
					if (module.isValid())
					{
						function = GetProcAddress(Utils::NT::Module::Load(name).getHandle(), MAKEINTRESOURCEA(IMAGE_ORDINAL(*nameTableEntry)));
					}

					functionName = Utils::String::VA("#%d", IMAGE_ORDINAL(*nameTableEntry));
				}
				else
				{
					auto import = PIMAGE_IMPORT_BY_NAME(target.getPtr() + *nameTableEntry);
					functionName = import->Name;

					if (this->importResolver) function = this->importResolver(name, functionName);
					if (!function)
					{
						Utils::NT::Module module = Utils::NT::Module::Load(name);
						if (module.isValid())
						{
							function = GetProcAddress(Utils::NT::Module::Load(name).getHandle(), functionName.data());
						}
					}
				}

				if (!function)
				{
					MessageBoxA(nullptr, Utils::String::VA("Unable to load import '%s' from module '%s'", functionName.data(), name.data()), nullptr, MB_ICONERROR);
					TerminateProcess(GetCurrentProcess(), 1);
				}

				*addressTableEntry = reinterpret_cast<uintptr_t>(function);

				nameTableEntry++;
				addressTableEntry++;
			}

			descriptor++;
		}
	}

	Syringe::Callback Syringe::inject(Utils::NT::Module module)
	{
		if (!module.isValid()) return nullptr;

		Utils::NT::Module source(HMODULE(this->data.data()));
		if (!source.isValid()) return nullptr;

		this->loadSections(module, source);
		this->loadImports(module, source);

		if (source.getOptionalHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size)
		{
			const IMAGE_TLS_DIRECTORY* targetTls = reinterpret_cast<PIMAGE_TLS_DIRECTORY>(module.getPtr() + module.getOptionalHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);
			const IMAGE_TLS_DIRECTORY* sourceTls = reinterpret_cast<PIMAGE_TLS_DIRECTORY>(module.getPtr() + source.getOptionalHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);

			*reinterpret_cast<DWORD*>(sourceTls->AddressOfIndex) = 0;

			DWORD oldProtect;
			VirtualProtect(PVOID(targetTls->StartAddressOfRawData), sourceTls->EndAddressOfRawData - sourceTls->StartAddressOfRawData, PAGE_READWRITE, &oldProtect);

			LPVOID tlsBase = *reinterpret_cast<LPVOID*>(__readfsdword(0x2C));
			std::memmove(tlsBase, PVOID(sourceTls->StartAddressOfRawData), sourceTls->EndAddressOfRawData - sourceTls->StartAddressOfRawData);
			std::memmove(PVOID(targetTls->StartAddressOfRawData), PVOID(sourceTls->StartAddressOfRawData), sourceTls->EndAddressOfRawData - sourceTls->StartAddressOfRawData);
		}

		// copy over the offset to the new imports directory
		DWORD oldProtect;
		VirtualProtect(module.getNTHeaders(), 0x1000, PAGE_EXECUTE_READWRITE, &oldProtect);

		module.getOptionalHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT] = source.getOptionalHeader()->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
		std::memmove(module.getNTHeaders(), source.getNTHeaders(), sizeof(IMAGE_NT_HEADERS) + (source.getNTHeaders()->FileHeader.NumberOfSections * (sizeof(IMAGE_SECTION_HEADER))));

		return Syringe::Callback(module.getPtr() + source.getRelativeEntryPoint());
	}

	void Syringe::setResolver(Syringe::Resolver resolver)
	{
		this->importResolver = resolver;
	}
}
