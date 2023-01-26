#include "STDInclude.hpp"

#include "Core/Loader.hpp"

namespace Loader
{
	bool PreDestroyed = false;
	bool Uninitializing = false;
	std::vector<std::unique_ptr<Components::IComponent>> LoadedComponents;

	void Initialize()
	{
		Loader::PreDestroyed = false;
		Utils::Memory::GetAllocator()->clear();

		using namespace Components;

		Loader::Register<Core>();
		Loader::Register<Linker>();
		Loader::Register<Command>();
		Loader::Register<Console>();
		Loader::Register<Scheduler>();
	}

	void Uninitialize()
	{
		Loader::Uninitializing = true;
		Loader::PreDestroy();

		std::reverse(Loader::LoadedComponents.begin(), Loader::LoadedComponents.end());
		Loader::LoadedComponents.clear();

		Utils::Memory::GetAllocator()->clear();
	}

	bool IsUninitializing()
	{
		return Loader::Uninitializing;
	}

	void PreDestroy()
	{
		if (!Loader::PreDestroyed)
		{
			Loader::PreDestroyed = true;

			for (auto& component : Loader::LoadedComponents)
			{
				component->preDestroy();
			}
		}
	}
}
