#include "Object/ObjectComponents/BlockComponents/destructible_by_explosion.h"


void Uranium::Creation::Components::BlockComponents::DestructibleByExplosion::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	// Handle it being undefined
	if (this->__initalized == false)
	{
		// Create a new object
		rapidjson::Value obj(rapidjson::kObjectType);
		// add a compnent with the name minecraft:destructible_by_explosion and the value of this->resistance
		obj.AddMember("explosion_resistance", this->resistance, allocator);
		// Push the object to the writeDoc
		writeDoc->AddMember("minecraft:destructible_by_explosion", obj, allocator);
	}
	else
	{
		// Just push a component with the name minecraft:destructible_by_explosion and the value of this->isDestructibleByExplosion
		writeDoc->AddMember("minecraft:destructible_by_explosion", this->isDestructibleByExplosion, allocator);
	}
}
