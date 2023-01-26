#pragma once

#ifndef RC_INVOKED

// Usefull for debugging
template <size_t S> class Sizer { };
#define BindNum(x, y) Sizer<x> y;
#define XSizeOf(x, y) BindNum(sizeof(x), y)
#define XOffsetOf(x, y, z) BindNum(offsetof(x, y), z)

#define STRINGIZE_(x) #x
#define STRINGIZE(x) STRINGIZE_(x)

#define AssertSize(x, size) static_assert(sizeof(x) == size, STRINGIZE(x) " structure has an invalid size.")
#define AssertOffset(x, y, offset) static_assert(offsetof(x, y) == offset, STRINGIZE(x) "::" STRINGIZE(y) " is not at the right offset.")

#define DATA_PATH "t6r"

#endif

// Resource stuff
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
// Defines below make accessing the resources from the code easier.
#define _APS_NEXT_RESOURCE_VALUE        102
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif
