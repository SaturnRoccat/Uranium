#pragma once
#include "CompilerObject.h"


namespace Uranium
{
	namespace Creation
	{
		class BlockObject : public BaseObject
		{
		public:
			BlockObject(std::string& name) : BaseObject(name) {
				std::string jsonData = R"({
                    "formatVersion": 0.0.0,
					"minecraft:block": {
					"description": {
					  "identifier": "",
					  "menu_category": {}
					},
					"components": {}
				  })";
				objectData = GlobalParser.parse(jsonData);
			}		

		};
	}
}