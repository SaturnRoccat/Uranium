#pragma once
#include "../../Utils/RandomTypes.h"
#include "../../Utils/RapidProxy.h"
#include "../../Utils/Macros.h"
#include <vector>
#include <array>
#include <tuple>
namespace Uranium
{
	namespace Creation
	{
		namespace GeometryUtilities
		{
			class Cube
			{
			private:
				Vec3f origin;
				Vec3f size;
				Vec3f rotation = {0, 0, 0};
				Vec3f pivot = {0, 0, 0};
				std::array<std::pair<Vec2i, Vec2i>, 6> uv;
			public:
				Cube(Vec3f origin, Vec3f size, std::array<std::pair<Vec2i, Vec2i>, 6> uv = { 
					{
						{
							{ 0, 0 }, { 1, 1 } 
						},
						{
							{ 0, 0 }, { 1, 1 } 
						},
						{
							{ 0, 0 }, { 1, 1 } 
						},
						{
							{ 0, 0 }, { 1, 1 } 
						},
						{
							{ 0, 0 }, { 1, 1 } 
						},
						{
							{ 0, 0 }, { 1, 1 } 
						}
					}
					},Vec3f rotation = { 0, 0, 0 }, Vec3f pivot = { 0, 0, 0 }) : origin(origin), size(size), uv(uv), rotation(rotation), pivot(pivot) {};
				Cube() {};
				// Getters
				Vec3f getOrigin() const { return origin; };
				Vec3f getSize() const { return size; };
				std::array<std::pair<Vec2i, Vec2i>, 6> getUV() const { return uv; };

				// Setters
				void setOrigin(Vec3f origin) { this->origin = origin; };
				void setSize(Vec3f size) { this->size = size; };
				void setUV(std::array<std::pair<Vec2i, Vec2i>, 6> uv) { this->uv = uv; };

				// Writer
				void WriteToJson(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) const;

			};

			class Bone
			{
			private:
				std::string name;
				Vec3f pivot;
				std::vector<Cube> cubes;
				std::string parent = "";
			public:

				Bone(std::string name, Vec3f pivot, std::vector<Cube> cubes, std::string parent = "") : name(name), pivot(pivot), cubes(cubes), parent(parent) {};
				Bone() {}

				// setters
				void inline addCube(Cube& cube) { cubes.push_back(cube); }
				void inline setName(std::string name) { this->name = name; }
				void inline setPivot(Vec3f pivot) { this->pivot = pivot; }
				void inline setParent(std::string parent) { this->parent = parent; }

				// getters
				std::string inline getName() const { return name; }
				Vec3f inline getPivot() const { return pivot; }
				inline std::vector<Cube>* getCubes() { return &cubes; }

				// writer
				void WriteToJson(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) const;
			};
		}
	}
}