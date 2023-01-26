#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

namespace Components
{
	class IComponent
	{
	public:
		IComponent() {}
		virtual ~IComponent() {}

#ifdef DEBUG
		virtual Utils::String getName()
		{
			return Utils::String(typeid(*this).name()).replaceAll("class Components::", "");
		}
#endif

		virtual void preDestroy() {}
	};
}
