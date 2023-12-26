#pragma once
#include "Bone.h"
namespace Uranium
{
	namespace Creation
	{
		namespace GeometryUtilities
		{
			enum class GeoType
			{
				Default,
				Polly
			};
			class Geometry
			{
			private:
				std::vector<Bone> bones;
				std::string identifier;
				int textureWidth;
				int textureHeight;
			    float visibleBoundsWidth;
				float visibleBoundsHeight;
				Vec3f visibleBoundsOffset;
				GeoType geoType = GeoType::Default;

				// handlers for the polly mesh 
				std::vector<Vec3f> positions;
				std::vector<Vec3f> normals;
				std::vector<Vec2i> uvs;

				std::vector<VariableLengthFixedSizeArray<int, 4>> polyData;
			public:
				Geometry(std::string identifier,
					int textureWidth,
					int textureHeight,
					float visibleBoundsWidth,
					float visibleBoundsHeight,
					Vec3f visibleBoundsOffset,
					std::vector<Bone> bones = {}) : 
					identifier(identifier),
					textureWidth(textureWidth),
					textureHeight(textureHeight),
					visibleBoundsWidth(visibleBoundsWidth),
					visibleBoundsHeight(visibleBoundsHeight),
					visibleBoundsOffset(visibleBoundsOffset),
					bones(bones)
				{
				}

				Geometry() {}

				Geometry(std::string objPath, int scale = 1);

				// Getters
				inline std::vector<Bone>& GetBones() { return bones; }
				inline std::string GetIdentifier() { return identifier; }
				inline int GetTextureWidth() { return textureWidth; }
				inline int GetTextureHeight() { return textureHeight; }
				inline float GetVisibleBoundsWidth() { return visibleBoundsWidth; }
				inline float GetVisibleBoundsHeight() { return visibleBoundsHeight; }
				inline Vec3f GetVisibleBoundsOffset() { return visibleBoundsOffset; }
				// Setters
				inline void SetBones(std::vector<Bone> bones) { this->bones = bones; }
				inline void SetIdentifier(std::string identifier) { this->identifier = identifier; }
				inline void SetTextureWidth(int textureWidth) { this->textureWidth = textureWidth; }
				inline void SetTextureHeight(int textureHeight) { this->textureHeight = textureHeight; }
				inline void SetVisibleBoundsWidth(float visibleBoundsWidth) { this->visibleBoundsWidth = visibleBoundsWidth; }
				inline void SetVisibleBoundsHeight(float visibleBoundsHeight) { this->visibleBoundsHeight = visibleBoundsHeight; }
				inline void SetVisibleBoundsOffset(Vec3f visibleBoundsOffset) { this->visibleBoundsOffset = visibleBoundsOffset; }

				// Functions
				inline void AddBone(Bone bone) { bones.push_back(bone); }
				inline void AddNormal(float normal) { normals.push_back(normal); }
				inline void AddPosition(float position) { positions.push_back(position); }
				inline void AddUV(Vec2i uv) { uvs.push_back(uv); }
				inline void AddPolyData(VariableLengthFixedSizeArray<int, 4> polyData) { this->polyData.push_back(polyData); }
				inline void SetGeoType(GeoType geoType) { this->geoType = geoType; }


				void WriteToJson(rapidjson::Document* writeDoc) const;
			private:
				void writePollyMesh(rapidjson::Value* writeDoc, rapidjson::Document::AllocatorType& allocator) const;
			};
		}
	}
}