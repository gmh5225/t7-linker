#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Game/Zone.hpp"

#include "Core/Component.hpp"

#include "Core/Components/Core.hpp"
#include "Core/Components/Linker.hpp"
#include "Core/Components/Command.hpp"
#include "Core/Components/Console.hpp"
#include "Core/Components/Scheduler.hpp"

namespace Loader
{
	extern std::vector<std::unique_ptr<Components::IComponent>> LoadedComponents;

	void Initialize();
	void Uninitialize();

	bool IsUninitializing();

	void PreDestroy();

	template <typename T> void Register()
	{
		static_assert(std::is_base_of<Components::IComponent, T>::value, "Component must inherit from Components::IComponent");

		auto component = std::make_unique<T>();

#ifdef DEBUG
		//Components::Console::Log("Registering component %s\n", component->getName().data());
#endif

		Loader::LoadedComponents.push_back(std::move(component));
	}

	template <typename T>
	T* GetInstance()
	{
		for (auto& component : Loader::LoadedComponents)
		{
			if (typeid(*(component.get())) == typeid(T))
			{
				return reinterpret_cast<T*>(component.get());
			}
		}

		return nullptr;
	}
}
