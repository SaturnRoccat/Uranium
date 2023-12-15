#include "Object/ObjectComponents/BlockComponents/friction.h"

void Uranium::Creation::Components::BlockComponents::Friction::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	rapidjson::Value frictionValue; 
	frictionValue.SetDouble(friction); 
	writeDoc->AddMember("minecraft:friction", frictionValue, allocator);
}
