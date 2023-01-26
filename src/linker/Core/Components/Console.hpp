#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Core/Component.hpp"

namespace Components
{
	class Console : public IComponent
	{
	public:
		Console();

		static void Info(const char* message, ...);
		static void Print(const char* message, ...);
		static void Error(const char* message, ...);

	private:
		static std::recursive_mutex Mutex;

		static void LogText(const char* text);
		static void LogError(const char* text);

		static BOOL WINAPI Handler(DWORD type);

		static WORD GetColor();
		static void SetColor(WORD color);
		static HANDLE GetConsoleHandle();
	};
}
