#pragma once
#include <Utils/RandomTypes.h>
#include <UUID_V4/UUID_V4.h>
#include <Utils/RapidProxy.h>

namespace Uranium
{
	static FormatVersion GlobalFormatVersion = FormatVersion(1, 20, 50);
	static FormatVersion GlobalBlockFormatVersion = GlobalFormatVersion;
	static std::string GlobalProjectNamespace;
	static UUIDv4::UUIDGenerator<std::mt19937_64> GlobalUUIDGenerator;
}
#ifndef URANIUM_FORMAT_1_20_50
	#define URANIUM_FORMAT_1_20_50 12050
#endif

