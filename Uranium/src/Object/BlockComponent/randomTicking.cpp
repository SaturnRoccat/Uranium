#include <Object/ObjectComponents/BlockComponents/randomTicking.h>

void Uranium::Creation::Components::BlockComponents::RandomTicking::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	rapidjson::Value RJ_onTick(rapidjson::kObjectType);
	this->onTick.getAsJsonData(&RJ_onTick, allocator, "on_tick");
	writeDoc->AddMember("minecraft:random_ticking", RJ_onTick, allocator);
}
