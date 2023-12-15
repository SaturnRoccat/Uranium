#include "Object/ObjectComponents/BlockComponents/materialInstances.h"


void Uranium::Creation::Components::BlockComponents::MaterialInstances::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	// create the json object
	rapidjson::Value materialJson(rapidjson::kObjectType);
	for (auto& i : this->materialInstances)
	{
		// create a json object for the material instance
		rapidjson::Value target(rapidjson::kObjectType);
		// add the material texture to the json object
		target.AddMember("texture", RJ_STL_S(i.texture), allocator);
		// add the renderMethod to the json object
		SET_IF_NOT_DEFAULT_EX(i.renderMethod, "opaque", target, allocator, "render_method", Uranium::Utils::StrToRJ, .)
		SET_IF_NOT_DEFAULT(i.faceDimming, true, target, allocator, "face_dimming", .)
		SET_IF_NOT_DEFAULT(i.ambientOcclusion, false, target, allocator, "ambient_occlusion", .)

		// add the json object to the material json object
		materialJson.AddMember(RJ_STL_S(i.target), target, allocator);
	}
	// add the material json object to the writeDoc
	writeDoc->AddMember("minecraft:material_instances", materialJson, allocator);
}