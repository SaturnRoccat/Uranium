#include "Object/ObjectComponents/BlockComponents/destructible_by_mining.h"


void Uranium::Creation::Components::BlockComponents::DestructibleByMining::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	// Handle it being undefined
	if (this->__initalized == false)
	{
		// Create a new object
		rapidjson::Value obj(rapidjson::kObjectType);
		// add a compnent with the name minecraft:destructible_by_mining and the value of this->resistance
		obj.AddMember("seconds_to_destroy", this->resistance, allocator);
		// Push the object to the writeDoc
		writeDoc->AddMember("minecraft:destructible_by_mining", obj, allocator);
	}
	else
	{
		// Just push a component with the nameminecraft:destructible_by_mining and the value of this->isDestructibleByExplosion
		writeDoc->AddMember("minecraft:destructible_by_mining", this->isDestructibleByExplosion, allocator);
	}
}
