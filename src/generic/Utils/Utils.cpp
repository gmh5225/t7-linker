#include "STDInclude.hpp"

namespace std
{
    std::wstring to_wstring(const std::string& string)
    {
        return std::wstring(string.begin(), string.end());
    }
    std::string to_string(const std::wstring& string)
    {
        return std::string(string.begin(), string.end());
    }
}

namespace Utils
{
#ifdef _WINDOWS
	void SetEnvironment()
	{
		wchar_t exeName[512];
		GetModuleFileName(GetModuleHandle(nullptr), exeName, sizeof(exeName) / 2);

		wchar_t* exeBaseName = wcsrchr(exeName, L'\\');
		exeBaseName[0] = L'\0';

		SetCurrentDirectory(exeName);
	}

	std::string LoadResource(int resId)
	{
		std::string result;

		HRSRC res = FindResource(GetModuleHandleA(nullptr), MAKEINTRESOURCE(resId), RT_RCDATA);
		if (!res) return "";

		HGLOBAL handle = LoadResource(nullptr, res);
		if (!handle) return "";

		return std::string(LPSTR(LockResource(handle)), SizeofResource(nullptr, res));
	}
#endif
}
