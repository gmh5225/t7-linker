#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Core/Component.hpp"

namespace Components
{
	class Command : public IComponent
	{
	public:
		Command();
		~Command();

		class Params
		{
		public:
			Params();
			~Params() {};
			const char* get(size_t index);
			size_t size();

			std::string join(size_t startIndex);
			const char* operator[](size_t index) { return this->get(index); }
		};

		static void Add(Utils::String command, Utils::Slot<void(Params)> handler);
		static void Execute(std::string command, bool sync = false);

	private:
		static std::map<std::string, Utils::Slot<void(Params)>> Handlers;

		static void Callback();
	};
}
