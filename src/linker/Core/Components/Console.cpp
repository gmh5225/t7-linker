#include "STDInclude.hpp"

#include "Game/Game.hpp"

#include "Core/Components/Command.hpp"
#include "Core/Components/Console.hpp"

namespace Components
{
	std::recursive_mutex Console::Mutex;

	void Console::Print(const char* message, ...)
	{
		std::lock_guard<std::recursive_mutex> _(Console::Mutex);

		static char buffer[32768];

		va_list va;
		va_start(va, message);
		_vsnprintf_s(buffer, sizeof(buffer), message, va);
		va_end(va);

		Console::LogText(buffer);
	}

	void Console::Info(const char* message, ...)
	{
		std::lock_guard<std::recursive_mutex> _(Console::Mutex);

		static char buffer[32768];

		va_list va;
		va_start(va, message);
		_vsnprintf_s(buffer, sizeof(buffer), message, va);
		va_end(va);

		auto color = Console::GetColor();
		Console::SetColor(11);

		Console::LogText(buffer);

		Console::SetColor(color);
	}

	void Console::Error(const char* message, ...)
	{
		std::lock_guard<std::recursive_mutex> _(Console::Mutex);

		static char buffer[32768];

		va_list va;
		va_start(va, message);
		_vsnprintf_s(buffer, sizeof(buffer), message, va);
		va_end(va);

		auto color = Console::GetColor();
		Console::SetColor(12);

		Console::LogError(buffer);

		Console::SetColor(color);
	}

	void Console::LogText(const char* text)
	{
		std::lock_guard<std::recursive_mutex> _(Console::Mutex);

		fwrite(text, 1, strlen(text), stdout);
		fflush(stdout);
	}

	void Console::LogError(const char* text)
	{
		std::lock_guard<std::recursive_mutex> _(Console::Mutex);

		fwrite(text, 1, strlen(text), stderr);
		fflush(stderr);
	}

	BOOL WINAPI Console::Handler(DWORD /*type*/)
	{
		Command::Execute("quit");
		while (true) std::this_thread::sleep_for(10ms);
		//return TRUE;
	}

	HANDLE Console::GetConsoleHandle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}

	WORD Console::GetColor()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		if (!GetConsoleScreenBufferInfo(Console::GetConsoleHandle(), &info)) return 0;
		return info.wAttributes;
	}

	void Console::SetColor(WORD color)
	{
		SetConsoleTextAttribute(Console::GetConsoleHandle(), color);
	}

	Console::Console()
	{
		// Block Sys_ShowConsole
		Utils::Hook::Set<BYTE>(0x7A4E00, 0xC3);

		Utils::Hook(0x7A4FE0, Console::LogText, HOOK_JUMP).install()->quick(); // Conbuf_AppendTextInMainThread
		Utils::Hook(0x79F6F0, Console::LogText, HOOK_JUMP).install()->quick(); // Sys_Print
		Utils::Hook(0x79F550, Console::Error, HOOK_JUMP).install()->quick();   // Sys_Error

		SetConsoleCtrlHandler(Console::Handler, TRUE);
	}
}
