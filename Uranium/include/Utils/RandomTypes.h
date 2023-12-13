#pragma once
#include <iostream>
#include <string>

namespace Uranium
{
	class FormatVersion
	{
	public:
		uint64_t major;
		uint64_t minor;
		uint64_t patch;

		FormatVersion(uint64_t major, uint64_t minor, uint64_t patch)
			: major(major), minor(minor), patch(patch) {}

		// Copy Constructor
		FormatVersion(const FormatVersion& other)
			: major(other.major), minor(other.minor), patch(other.patch) {}

		// Overloading the assignment operator for conventional assignment
		FormatVersion& operator=(const FormatVersion& other) {
			if (this != &other) {
				major = other.major;
				minor = other.minor;
				patch = other.patch;
			}
			return *this;
		}

		// Overloading the << operator for outputting the version
		friend std::ostream& operator<<(std::ostream& os, const FormatVersion& version) {
			os << version.major << '.' << version.minor << '.' << version.patch;
			return os;
		}

		bool operator==(const FormatVersion& other) const {
			return major == other.major && minor == other.minor && patch == other.patch;
		}

		bool operator!=(const FormatVersion& other) const {
			return !(*this == other);
		}
		inline std::string toString() const {
			return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
		}
	};
}
