#pragma once

#define STD_INCLUDED

// Version number
#include "version.h"

#ifndef RC_INVOKED

#define _HAS_CXX17 1
#define VC_EXTRALEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

// Requires Visual Leak Detector plugin: http://vld.codeplex.com/
#define VLD_FORCE_ENABLE
//#include <vld.h>

#include <windows.h>
#include <assert.h>
#include <intrin.h>
#include <Shellapi.h>
#include <winternl.h>
#include <VersionHelpers.h>

#include <WinSock2.h>
#include <ws2tcpip.h>

#include <wincrypt.h>

#include <d3d11.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "Crypt32.lib")

// Delay import
#include <delayimp.h>
#pragma comment(lib, "delayimp.lib")

#pragma warning(push)
#pragma warning(disable: 4091)
#pragma warning(disable: 4244)
#include <dbghelp.h>

#include <map>
#include <mutex>
#include <fstream>
#include <thread>
#include <unordered_map>
#include <queue>
#include <random>
#include <atomic>
#include <regex>

// Experimental C++17 features
#include <filesystem>
#include <optional>

#pragma warning(pop)

// Submodules
// Ignore the warnings, it's not our code!
#pragma warning(push)
#pragma warning(disable: 4100)
#pragma warning(disable: 4146)
#pragma warning(disable: 4389)
#pragma warning(disable: 4996)
#pragma warning(disable: 6001)
#pragma warning(disable: 6031)
#pragma warning(disable: 6255)
#pragma warning(disable: 6258)
#pragma warning(disable: 6386)
#pragma warning(disable: 6387)

#include <zlib.h>
#include <udis86.h>
#include <tomcrypt.h>
#include <ecrypt-sync.h>

#pragma warning(pop)

// Enable additional literals
using namespace std::literals;

#include "Utils/IO.hpp"
#include "Utils/NT.hpp"
#include "Utils/Lock.hpp"
#include "Utils/Time.hpp"
#include "Utils/Flags.hpp"
#include "Utils/Queue.hpp"
#include "Utils/Utils.hpp"
#include "Utils/Signal.hpp"
#include "Utils/Memory.hpp"
#include "Utils/String.hpp"
#include "Utils/Hooking.hpp"
#include "Utils/Compression.hpp"
#include "Utils/Cryptography.hpp"
#include "Utils/Salsa20.hpp"
#include "Utils/CSV.hpp"

#endif

#include <Common.hpp>

#define BINARY_PAYLOAD_SIZE 0x60000000
#define DEDI_BINARY         300
