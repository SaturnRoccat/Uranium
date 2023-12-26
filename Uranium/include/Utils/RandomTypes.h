#pragma once
#include <iostream>
#include <string>
#include <array>

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
		Vector3(T x = 0, T y = 0, T z = 0)
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

	template<typename T>
	class Vector2
	{
	public:
		Vector2(T x = 0, T y = 0)
			: x(x), y(y) {}
		T x;
		T y;
		// Copy Constructor
		Vector2(const Vector2& other)
			: x(other.x), y(other.y) {}
		// Overloading the assignment operator for conventional assignment
		Vector2& operator=(const Vector2& other) {
			if (this != &other) {
				x = other.x;
				y = other.y;
			}
			return *this;
		}
		// Overloading the << operator for outputting the version
		friend std::ostream& operator<<(std::ostream& os, const Vector2& vector) {
			os << vector.x << ',' << vector.y;
			return os;
		}
		bool operator==(const Vector2& other) const {
			return x == other.x && y == other.y;
		}
		bool operator!=(const Vector2& other) const {
			return !(*this == other);
		}
		inline std::string toString() const {
			return std::to_string(x) + "," + std::to_string(y);
		}
		inline Vector2 operator+(const Vector2& other) const {
			return Vector2(x + other.x, y + other.y);
		}
		inline Vector2 operator-(const Vector2& other) const {
			return Vector2(x - other.x, y - other.y);
		}
		inline Vector2 operator*(const Vector2& other) const {
			return Vector2(x * other.x, y * other.y);
		}
		inline Vector2 operator/(const Vector2& other) const {
			return Vector2(x / other.x, y / other.y);
		}
		inline Vector2 operator+(const T& other) const {
			return Vector2(x + other, y + other);
		}
		inline Vector2 operator-(const T& other) const {
			return Vector2(x - other, y - other);
		}
		inline Vector2 operator*(const T& other) const {
			return Vector2(x * other, y * other);
		}
		inline Vector2 operator/(const T& other) const {
			return Vector2(x / other, y / other);
		}
		inline Vector2& operator+=(const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		inline Vector2& operator-=(const Vector2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline Vector2& operator*=(const Vector2& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}
		inline Vector2& operator/=(const Vector2& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}
		inline std::array<T, 2> toArray() const {
			return { x, y };
		}
	};

	template<typename T, int maxSize = 4>
	class VariableLengthFixedSizeArray
	{
	public:
		VariableLengthFixedSizeArray(size_t size = maxSize)
		{
			maxIndexSize = size;
			if (maxIndexSize > maxSize)
				throw std::out_of_range("Index out of range");
			// Fill the array with the default value using algorithm
			std::fill(data.begin(), data.end(), T());
		}

		VariableLengthFixedSizeArray(std::initializer_list<T> list)
		{
			maxIndexSize = list.size();
			if (maxIndexSize > maxSize)
				throw std::out_of_range("Index out of range");
			// Fill the array with the default value using algorithm
			std::copy(list.begin(), list.end(), data.begin());
		})

		// [] operator support
		T& operator[](size_t index)
		{
			if (index >= maxIndexSize)
				throw std::out_of_range("Index out of range");
			return data[index];
		}

		// const [] operator support
		const T& operator[](size_t index) const
		{
			if (index >= maxIndexSize)
				throw std::out_of_range("Index out of range");
			return data[index];

		}

		// begin
		T* begin()
		{
			return data.data();
		}

		// end
		T* end()
		{
			return data.data() + maxIndexSize;
		}

		// size
		size_t size() const
		{
			return maxIndexSize;
		}

		// empty
		bool empty() const
		{
			return maxIndexSize == 0;
		}

		// front
		T& front()
		{
			return data[0];
		}

		// back
		T& back()
		{
			return data[maxIndexSize - 1];
		}

		// at
		T& at(size_t index)
		{
			if (index >= maxIndexSize)
				throw std::out_of_range("Index out of range");
			return data[index];
		}

		// data
		T* data()
		{
			return data.data();
		}

		// max_size
		size_t max_size() const
		{
			return maxSize;
		}

		// fill
		void fill(const T& value)
		{
			std::fill(data.begin(), data.end(), value);
		}

		// swap
		void swap(VariableLengthFixedSizeArray& other)
		{
			std::swap(data, other.data);
			std::swap(maxIndexSize, other.maxIndexSize);
		}
	
	private:
		std::array<T, maxSize> data;
		size_t maxIndexSize;
	};
}
typedef Uranium::Vector2<float> Vec2f;
typedef Uranium::Vector2<double> Vec2d;
typedef Uranium::Vector2<int> Vec2i;



typedef Uranium::Vector3<float> Vec3f;
typedef Uranium::Vector3<double> Vec3d;
typedef Uranium::Vector3<int> Vec3i;
typedef const std::string& ConstStringRef;