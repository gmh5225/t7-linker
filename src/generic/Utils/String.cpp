#include "STDInclude.hpp"

namespace Utils
{
	const char *String::VA(const char *fmt, ...)
	{
		static
#ifndef VA_DONT_USE_THREAD_STORAGE
			thread_local
#endif
			String::VAProvider<8, 256> provider;

		va_list ap;
		va_start(ap, fmt);

		const char* result = provider.get(fmt, ap);

		va_end(ap);
		return result;
	}

	std::string String::DumpHex(std::string data, std::string separator)
	{
		std::string result;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			if (i > 0)
			{
				result.append(separator);
			}

			result.append(Utils::String::VA("%02X", data[i] & 0xFF));
		}

		return result;
	}

	String String::toLower()
	{
		String out(*this);
		std::transform(out.begin(), out.end(), out.begin(), ::tolower);
		return out;
	}

	String String::toUpper()
	{
		String out(*this);
		std::transform(out.begin(), out.end(), out.begin(), ::toupper);
		return out;
	}

	bool String::endsWith(Utils::String otherString)
	{
		if (otherString.size() > this->size()) return false;
		return std::equal(otherString.begin(), otherString.end(), this->begin() + (this->size() - otherString.size()));
	}

	bool String::startsWith(Utils::String otherString)
	{
        if (this->empty() || otherString.empty()) return false;
		return std::equal(otherString.begin(), otherString.end(), this->begin());
	}

	String String::replaceAll(std::string find, std::string replace)
	{
		size_t pos = 0;
		String string(*this);
		while ((pos = string.find(find, pos)) != std::string::npos)
		{
			string = string.replace(pos, find.size(), replace);
			pos += replace.length();
		}

		return string;
	}

    std::vector < String > String::split(const String& rawInput, const std::vector < char >& delims)
    {
        std::vector < Utils::String > strings;

        auto findFirstDelim = [](const std::string& input, const std::vector < char >& delims) -> std::pair < char, std::size_t>
        {
            auto firstDelim = 0;
            auto firstDelimIndex = static_cast<std::size_t>(-1);
            auto index = 0u;

            for (auto& delim : delims)
            {
                if ((index = input.find(delim)) != std::string::npos)
                {
                    if (firstDelimIndex == -1 || index < firstDelimIndex)
                    {
                        firstDelim = delim;
                        firstDelimIndex = index;
                    }
                }
            }

            return { firstDelim, firstDelimIndex };
        };

        std::string input = rawInput;

        while (!input.empty())
        {
            auto splitDelim = findFirstDelim(input, delims);
            if (splitDelim.first != 0)
            {
                strings.push_back(input.substr(0, splitDelim.second));
                input = input.substr(splitDelim.second + 1);
            }
            else
            {
                break;
            }
        }

        strings.push_back(input);
        return strings;
    }
}
