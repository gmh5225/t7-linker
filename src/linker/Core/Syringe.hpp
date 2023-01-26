#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

namespace Core
{
	class Syringe
	{
	public:
		typedef void(*Callback)();
		typedef std::function<FARPROC(Utils::String, Utils::String)> Resolver;

		Syringe(const std::string& data);

		Callback inject(Utils::NT::Module module);

		void setResolver(Resolver resolver);

	private:
		std::string data;
		Resolver importResolver;

		void loadSection(Utils::NT::Module target, Utils::NT::Module source, IMAGE_SECTION_HEADER* section);
		void loadSections(Utils::NT::Module target, Utils::NT::Module source);
		void loadImports(Utils::NT::Module target, Utils::NT::Module source);
	};
}