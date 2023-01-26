#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#ifdef _WIN32

namespace Utils
{
	namespace Flags
	{
        std::string GetFlagValue(const std::string& flag, const std::string& defaultValue = "");
		bool Has(std::string flag);
	}
}

#endif
