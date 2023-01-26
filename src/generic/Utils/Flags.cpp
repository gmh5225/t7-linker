#include "STDInclude.hpp"

#ifdef _WIN32

namespace Utils
{
	namespace Flags
	{
        std::string GetFlagValue(const std::string& flag, const std::string& defaultValue)
        {
            auto strings = Utils::String::split(GetCommandLineA(), ' ');

            for (auto idx = 0u; idx < strings.size(); idx++)
            {
                if (idx != strings.size() - 1 && (strings[idx] == ("+" + flag) || strings[idx] == ("-" + flag)))
                {
                    return strings[idx + 1];
                }

                if (idx != strings.size() - 2 && (strings[idx] == "+set" || strings[idx] == "-set") && strings[idx + 1] == flag)
                {
                    return strings[idx + 2];
                }
            }

            return defaultValue;
        }

		bool Has(std::string flag)
		{
			static std::optional<std::vector<std::string>> flags;

			if (!flags.has_value())
			{
				int numArgs;
				LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &numArgs);

				std::vector<std::string> enabledFlags;

				if (argv)
				{
					for (int i = 0; i < numArgs; ++i)
					{
						std::wstring wFlag(argv[i]);
						if (wFlag[0] == L'-')
						{
							enabledFlags.push_back(std::string(++wFlag.begin(), wFlag.end()));
						}
					}

					LocalFree(argv);
				}

				flags.emplace(enabledFlags);
			}

			return std::find(flags->begin(), flags->end(), flag) != flags->end();
		}
	}
}

#endif
