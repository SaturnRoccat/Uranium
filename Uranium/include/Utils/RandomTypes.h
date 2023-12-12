#pragma once
#include <stdint.h>
#include <string>

namespace Uranium
{
	class FormatVersion
	{
	public:
		uint64_t major;
		uint64_t minor;
		uint64_t patch;
		FormatVersion(uint64_t major, uint64_t minor, uint64_t patch) {
			this->major = major;
			this->minor = minor;
			this->patch = patch;
		}
		FormatVersion(FormatVersion& other) {
			major = other.major;
			minor = other.minor;
			patch = other.patch;
		}

		std::string operator=(const FormatVersion& other) {
			return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
		}

		bool operator==(const FormatVersion& other) {
			return major == other.major && minor == other.minor && patch == other.patch;
		}
		bool operator!=(const FormatVersion& other) {
			return major != other.major || minor != other.minor || patch != other.patch;
		}

	};
}