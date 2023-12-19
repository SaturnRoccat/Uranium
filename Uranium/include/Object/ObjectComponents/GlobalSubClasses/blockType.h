#pragma once
#include <vector>
#include <string>
#include <any>
#include <Utils/RapidProxy.h>
#include <Utils/RandomTypes.h>
#include <Utils/macros.h>
namespace Uranium
{
	namespace Creation
	{
		namespace SubClasses
		{
			class BlockType
			{
			private:
				std::string name;
				std::vector<std::pair<std::string, std::any>> states;
			public:
				BlockType(std::string name, std::vector<std::pair<std::string, std::any>> states = {})
					: name(name), states(states) {}
				void GetAsJson(rapidjson::Value* writeJson, rapidjson::MemoryPoolAllocator<>& allocator, std::string name = "block_type")
				{
					rapidjson::Value blockType;
					if (states.size() != 0)
					{
						blockType.SetObject();
						blockType.AddMember("name", RJ_STL_S(name), allocator);
						rapidjson::Value statesJson;
						statesJson.SetObject();
						for (auto& state : states)
						{
							rapidjson::Value stateValue;
							if (state.second.type() == typeid(std::string))
								stateValue.SetString(RJ_STL_S(std::any_cast<std::string>(state.second)));
							else if (state.second.type() == typeid(int))
								stateValue.SetInt(std::any_cast<int>(state.second));
							else if (state.second.type() == typeid(float))
								stateValue.SetDouble(std::any_cast<float>(state.second));
							else if (state.second.type() == typeid(double))
								stateValue.SetDouble(std::any_cast<double>(state.second));
							else if (state.second.type() == typeid(bool))
								stateValue.SetBool(std::any_cast<bool>(state.second));
							else
								throw std::runtime_error("Invalid state type ");
							statesJson.AddMember(RJ_STL_S(state.first), stateValue, allocator);
						}
						blockType.AddMember("states", statesJson, allocator);
					}
					else
					{
						blockType.SetString(RJ_STL_S(name));
					}
					writeJson->AddMember("block_type", blockType, allocator);
				}
			};
		}
	}
}