#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Core/Component.hpp"

namespace Components
{
	class Core : public IComponent
	{
	public:
		Core();

	private:
		static void Initialize();

		static Game::FastFile BuildZone(std::string name);
	};
}
