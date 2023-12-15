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

	template<typename T>
	class Vector3
	{
	public:
		Vector3(T x, T y, T z)
			: x(x), y(y), z(z) {}
		T x;
		T y;
		T z;

		// Copy Constructor
		Vector3(const Vector3& other)
			: x(other.x), y(other.y), z(other.z) {}

		// Overloading the assignment operator for conventional assignment
		Vector3& operator=(const Vector3& other) {
			if (this != &other) {
				x = other.x;
				y = other.y;
				z = other.z;
			}
			return *this;
		}

		// Overloading the << operator for outputting the version
		friend std::ostream& operator<<(std::ostream& os, const Vector3& vector) {
			os << vector.x << ',' << vector.y << ',' << vector.z;
			return os;
		}

		bool operator==(const Vector3& other) const {
			return x == other.x && y == other.y && z == other.z;
		}

		bool operator!=(const Vector3& other) const {
			return !(*this == other);
		}

		inline std::string toString() const {
			return std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z);
		}

		inline Vector3 operator+(const Vector3& other) const {
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		inline Vector3 operator-(const Vector3& other) const {
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		inline Vector3 operator*(const Vector3& other) const {
			return Vector3(x * other.x, y * other.y, z * other.z);
		}

		inline Vector3 operator/(const Vector3& other) const {
			return Vector3(x / other.x, y / other.y, z / other.z);
		}

		inline Vector3 operator+(const T& other) const {
			return Vector3(x + other, y + other, z + other);
		}

		inline Vector3 operator-(const T& other) const {
			return Vector3(x - other, y - other, z - other);
		}

		inline Vector3 operator*(const T& other) const {
			return Vector3(x * other, y * other, z * other);
		}

		inline Vector3 operator/(const T& other) const {
			return Vector3(x / other, y / other, z / other);
		}

		inline Vector3& operator+=(const Vector3& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		inline Vector3& operator-=(const Vector3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		inline Vector3& operator*=(const Vector3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		inline Vector3& operator/=(const Vector3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		inline std::array<T, 3> toArray() const {
			return { x, y, z };
		}

	};


	typedef Vector3<float> Vec3f;
	typedef Vector3<double> Vec3d;
	typedef Vector3<int> Vec3i;
	
}

typedef const std::string& ConstStringRef;