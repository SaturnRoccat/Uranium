#include <RPUtils/GeometryUtilities/Bone.h>
namespace Uranium
{
	namespace Creation
	{
		namespace GeometryUtilities
		{
			void Cube::WriteToJson(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) const
			{
				// We assume that write doc is an object and just write to it
				RJ_STL_V_A(RJ_Origin, this->origin.toArray(), allocator)
				RJ_STL_V_A(RJ_Size, this->size.toArray(), allocator)
				// Write the simple arrays now 
				writeDoc->AddMember("origin", RJ_Origin, allocator);
				writeDoc->AddMember("size", RJ_Size, allocator);

				auto indexToDir = [](int i) -> std::string {
					switch (i)
					{
					case 0:
						return "north";
					case 1:
						return "east";
					case 2:
						return "south";
					case 3:
						return "west";
					case 4:
						return "up";
					case 5:
						return "down";
					default:
						Uranium::Logs::Logger::Error("Invalid Index For UVs. This should never happen due to it being hard coded so you have fucked up somewhere");
					}
				};
				rapidjson::Value RJ_UVObj(rapidjson::kObjectType);
				// Handle the Uvs
				for (int i = 0; i < this->uv.size(); i++)
				{
					rapidjson::Value UVFaceObject(rapidjson::kObjectType);
					auto& uvPair = this->uv[i];
					RJ_STL_V_A_Q(uvPair.first.toArray(), "uv", UVFaceObject, .)
					RJ_STL_V_A_Q(uvPair.first.toArray(), "uv_size", UVFaceObject, .)

					RJ_UVObj.AddMember(RJ_STL_S(indexToDir(i)), UVFaceObject, allocator);
				}
				writeDoc->AddMember("uv", RJ_UVObj, allocator);

				if (this->rotation != Vec3f(0.f, 0.f, 0.f))
				{
					RJ_STL_V_A_Q(this->pivot.toArray(), "pivot", writeDoc, ->)
					RJ_STL_V_A_Q(this->rotation.toArray(), "rotation", writeDoc, ->)
				}
			}
			void Bone::WriteToJson(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) const
			{
				// We assume that the writeDoc is an object and write into it directly 

				writeDoc->AddMember("name", RJ_STL_S(this->name), allocator);
				SET_IF_NOT_DEFAULT_EX(this->parent, "", writeDoc, allocator, "parent", RJ_STL_S, ->)
				RJ_STL_V_A_Q(this->pivot.toArray(), "pivot", writeDoc, ->)
				// Create the cube array
				rapidjson::Value cubes(rapidjson::kArrayType);
				for (auto& cube : this->cubes)
				{
					rapidjson::Value cubeObj(rapidjson::kObjectType);
					cube.WriteToJson(&cubeObj, allocator);
					cubes.PushBack(cubeObj, allocator);
				}
				writeDoc->AddMember("cubes", cubes, allocator);
			}
		}
	}
}