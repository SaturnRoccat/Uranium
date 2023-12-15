#pragma once
#include "BlockComponent.h"

COMPONENT_DEFINE_SINGLE_TYPE_EX(Loot, std::string, BlockComponent, "minecraft:loot", BlockComponents, "minecraft:empty", Utils::StrToRJ)