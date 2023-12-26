#include <RPUtils/GeometryUtilities/Geometry.h>
namespace Uranium
{
	namespace Creation
	{
		namespace GeometryUtilities
		{
			/*
			* We are compiling for this schema
			* object "poly_mesh" :
                    {
                        array "polys"
                        {
                            array "<any array element>"[3,4] : opt
                            {
                                array "<any array element>"[3]
                                {
                                    float "<any array element>" // Poly element indices, as an array of polygons, each an array of either three or four vertices, each an array of indices into positions, normals, and UVs (in that order).
                                }
                            }
                        }
                        string "polys"<"tri_list", "quad_list"> // If not specifying vertex indices, arrays of data must be a list of tris or quads, set by making this property either "tri_list" or "quad_list"
                    }
                }
			*/
			void Geometry::writePollyMesh(rapidjson::Value* writeDoc, rapidjson::Document::AllocatorType& allocator) const
			{
				rapidjson::Value facesArry(rapidjson::kArrayType);

				// Create the poly_mesh object
				rapidjson::Value polyMesh(rapidjson::kObjectType);

				// set it to normalized uvs
				// No config due to me being lazy
				polyMesh.AddMember("normalized_uvs", true, allocator);
				
				// implement positions
				rapidjson::Value positions(rapidjson::kArrayType);
				for (auto& position : this->positions)
				{
					RJ_STL_V_A(RJ_position, position.toArray(), allocator)
					positions.PushBack(RJ_position, allocator);
				}
				polyMesh.AddMember("positions", positions, allocator);

				// implement normals
				rapidjson::Value normals(rapidjson::kArrayType);	
				for (auto& normal : this->normals)
				{
					RJ_STL_V_A(RJ_normal, normal.toArray(), allocator)
					normals.PushBack(RJ_normal, allocator);
				}
				polyMesh.AddMember("normals", normals, allocator);

				// implement uvs
				rapidjson::Value uvs(rapidjson::kArrayType);
				for (auto& uv : this->uvs)
				{
					RJ_STL_V_A(RJ_uv, uv.toArray(), allocator)
					uvs.PushBack(RJ_uv, allocator);
				}
				polyMesh.AddMember("uvs", uvs, allocator);
			}

			void Geometry::WriteToJson(rapidjson::Document* writeDoc) const
			{
				// We are going to assume we have been passed an empty json document

				// We are going to use the allocator from the document
				rapidjson::Document::AllocatorType& allocator = writeDoc->GetAllocator();

				writeDoc->AddMember("format_version", RJ_STL_S(Uranium::GlobalFormatVersion.toString()), allocator);
				// Create the geo array for some reason its an array
				rapidjson::Value geoObject(rapidjson::kArrayType);

				// Create the geo object
				rapidjson::Value geo(rapidjson::kObjectType);

				// Add the description
				rapidjson::Value description(rapidjson::kObjectType);
				description.AddMember("identifier", RJ_STL_S(this->identifier), allocator);
				description.AddMember("texture_width", this->textureWidth, allocator);
				description.AddMember("texture_height", this->textureHeight, allocator);
				description.AddMember("visible_bounds_width", this->visibleBoundsWidth, allocator);
				description.AddMember("visible_bounds_height", this->visibleBoundsHeight, allocator);
				RJ_STL_V_A_Q(this->visibleBoundsOffset.toArray(), "visible_bounds_offset", description, .)

				// Add the description to the geo object
				geo.AddMember("description", description, allocator);


				if (this->geoType == GeometryUtilities::GeoType::Polly)
				{
					this->writePollyMesh(&geo, allocator);
				}

				// Create bones array
				rapidjson::Value bones(rapidjson::kArrayType);
				for (auto& bone : this->bones)
				{
					// Create an empty bone object
					rapidjson::Value boneObject(rapidjson::kObjectType);
					bone.WriteToJson(&boneObject, allocator);
					bones.PushBack(boneObject, allocator);
				}

				// Add the bones array to the geo object
				geo.AddMember("bones", bones, allocator);

				// add the geo object to the geo array
				geoObject.PushBack(geo, allocator);

				// Add the geo array to the document
				writeDoc->AddMember("minecraft:geometry", geoObject, allocator);
			}
			Geometry::Geometry(std::string objPath, int scale = 1)
			{
				geoType = GeoType::Polly;
				std::ifstream objFile(objPath);
				if (!objFile.is_open())
					Logs::Logger::Error("Failed to open obj file: {}", objPath);

				std::string line;

				while (std::getline(objFile, line))
				{
					// Pull the prefix off the line
					std::string prefix = line.substr(0, line.find(' '));
					std::string data = line.substr(line.find(' ') + 1);

					// Check if the prefix is a comment
					if (prefix == "#")
						continue;

					// If else chain to check the prefix
					if (prefix == "v")
					{
						
						
					}
					else if (prefix == "vn")
					{
					}
					else if (prefix == "vt")
					{
					}
					else if (prefix == "f")
					{
					}
				}

			}

		}
	}
}