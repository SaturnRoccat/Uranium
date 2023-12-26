#pragma once
// This file only exists because of rapidjson not compiling on C++17 or higher
#undef min
#undef max
#pragma warning(disable : 4996)
#pragma warning(disable : 4267)
#pragma warning(disable : 26451)
#pragma warning(disable : 26495)
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#pragma warning(default : 26451)
#pragma warning(default : 4996)
#pragma warning(default : 4267)
#pragma warning(default : 26495)