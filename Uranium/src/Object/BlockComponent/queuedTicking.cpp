#include <Object/ObjectComponents/BlockComponents/queuedTicking.h>

void Uranium::Creation::Components::BlockComponents::queuedTicking::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
	rapidjson::Value queuedTicking(rapidjson::kObjectType);
	RJ_STL_V_A(RJ_intervalRange, this->intervalRange, allocator);
	queuedTicking.AddMember("interval_range", RJ_intervalRange, allocator);
	queuedTicking.AddMember("looping", this->looping, allocator);

	rapidjson::Value RJ_onTick(rapidjson::kObjectType);
	RJ_onTick.AddMember("condition", RJ_STL_S(this->onTick.condition), allocator);
	RJ_onTick.AddMember("event", RJ_STL_S(this->onTick.event), allocator);
	RJ_onTick.AddMember("target", RJ_STL_S(this->onTick.target), allocator);

	queuedTicking.AddMember("on_tick", RJ_onTick, allocator);

	writeDoc->AddMember("minecraft:queued_ticking", queuedTicking, allocator);
}
