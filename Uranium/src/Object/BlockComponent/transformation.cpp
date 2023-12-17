#include <Object/ObjectComponents/BlockComponents/transformation.h>

void Uranium::Creation::Components::BlockComponents::Transformation::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	RJ_STL_V_A(transformation, this->translation, allocator);
	RJ_STL_V_A(scale, this->scale, allocator);
	RJ_STL_V_A(rotation, this->rotation, allocator);

	rapidjson::Value transformationObject(rapidjson::kObjectType);
	transformationObject.AddMember("translation", transformation, allocator);
	transformationObject.AddMember("scale", scale, allocator);
	transformationObject.AddMember("rotation", rotation, allocator);

	writeDoc->AddMember("minecraft:transformation", transformationObject, allocator);
}
