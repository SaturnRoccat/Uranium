#include "Object/ObjectComponents/BlockComponents/flammable.h"

void Uranium::Creation::Components::BlockComponents::Flammable::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	if (this->__inited)
	{
		// Just add a string to a bool
		writeDoc->AddMember("minecraft:flammable", this->canCatchFire, allocator);
	}
	else
	{
		// Create a new object
		rapidjson::Value flammableObject(rapidjson::kObjectType);
		flammableObject.AddMember("catch_chance_modifier", this->catchChanceModifier, allocator);
		flammableObject.AddMember("destroy_chance_modifier", this->destroyChanceModifier, allocator);

		writeDoc->AddMember("minecraft:flammable", flammableObject, allocator);
	}
}
