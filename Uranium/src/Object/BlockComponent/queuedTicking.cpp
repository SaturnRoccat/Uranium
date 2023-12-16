#include <Object/ObjectComponents/BlockComponents/queuedTicking.h>

void Uranium::Creation::Components::BlockComponents::queuedTicking::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	rapidjson::Value queuedTicking(rapidjson::kObjectType);
	RJ_STL_V_A(RJ_intervalRange, this->intervalRange, allocator);
	queuedTicking.AddMember("interval_range", RJ_intervalRange, allocator);
	queuedTicking.AddMember("looping", this->looping, allocator);

	rapidjson::Value RJ_onTick(rapidjson::kObjectType);
	this->onTick.getAsJsonData(&RJ_onTick, allocator, "on_tick");

	writeDoc->AddMember("minecraft:queued_ticking", queuedTicking, allocator);
}
