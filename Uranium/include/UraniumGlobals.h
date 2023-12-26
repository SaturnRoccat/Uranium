#pragma once
#include <Utils/RandomTypes.h>
#include <UUID_V4/UUID_V4.h>
#include <Utils/RapidProxy.h>

namespace Uranium
{
    // Declarations in the header file
    extern FormatVersion GlobalFormatVersion;
    extern FormatVersion GlobalBlockFormatVersion;
    extern std::string GlobalProjectNamespace;
    extern UUIDv4::UUIDGenerator<std::mt19937_64> GlobalUUIDGenerator;

    void SetGlobalProjectNamespace(const std::string& newValue);
}

#define EXPOSE_DEBUG_FUNCTIONS 1

#ifndef URANIUM_FORMAT_1_20_50
	#define URANIUM_FORMAT_1_20_50 12050
#endif

#ifndef URANIUM_FORMAT_1_20_51
	#define URANIUM_FORMAT_1_20_51 12051
#endif


#ifndef URANIUM_TARGET_FORMAT_VERSION
    #define URANIUM_TARGET_FORMAT_VERSION URANIUM_FORMAT_1_20_51
#endif