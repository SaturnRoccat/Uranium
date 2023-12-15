#pragma once
#include "BlockComponent.h"

COMPONENT_DEFINE_SINGLE_TYPE_EX(MapColor, std::string, BlockComponent, "minecraft:map_color", BlockComponents, "#ABCDEF", Utils::StrToRJ)