#include "Object/ObjectComponents/BlockComponents/display_name.h"

void Uranium::Creation::Components::BlockComponents::DisplayName::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	rapidjson::Value displayName;
	displayName.SetString(RJ_STL_S(name), allocator);
	writeDoc->AddMember("minecraft:display_name", displayName, allocator);
}
