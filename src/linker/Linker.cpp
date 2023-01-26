#include "STDInclude.hpp"

#include "Core/Syringe.hpp"
#include "Core/Loader.hpp"

namespace Main
{
	void Initialize()
	{
		srand(uint32_t(time(nullptr)));

		Utils::SetEnvironment();

		Utils::NT::Module self;
		Utils::IO::File selfFile(self.getName());
		Utils::IO::File debugFile("__" + selfFile.getName(false));
		debugFile.remove();
	}

	void Uninitialize()
	{
		Loader::Uninitialize();
		//google::protobuf::ShutdownProtobufLibrary();
	}

	void InitializePostInject()
	{
		Loader::Initialize();
		atexit(Loader::Uninitialize);
	}

	VOID WINAPI ExitProcessStub(UINT uExitCode)
	{
		exit(uExitCode);
	}

	FARPROC ImportResolver(Utils::String module, Utils::String process)
	{
		Utils::NT::Module self;

		if (module.toLower() == "steam_api.dll") return FARPROC(0x1);
		if (module.toLower() == "binkw32.dll") return FARPROC(0x1);
		if (module.toLower() == "kernel32.dll" && process == "ExitProcess")
		{
			return FARPROC(Main::ExitProcessStub);
		}

		return nullptr;
	}

	Core::Syringe::Callback InjectModule()
	{
		Utils::NT::Module self;

		auto data = Utils::LoadResource(DEDI_BINARY);
		data = Utils::Compression::ZLib::Decompress(data);

		Core::Syringe loader(data);
		loader.setResolver(Main::ImportResolver);

		Core::Syringe::Callback entryPoint = loader.inject(self);
		if (!entryPoint) MessageBoxA(nullptr, "Unable to initialize the linker", "Error", MB_ICONERROR);

		return entryPoint;
	}
}

void main()
{
	Main::Initialize();
	Core::Syringe::Callback entryPoint = Main::InjectModule();
	Main::InitializePostInject();
	if (entryPoint) entryPoint();
}
