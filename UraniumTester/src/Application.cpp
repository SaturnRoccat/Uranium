#include "Application.h"
#include <Logger/Logger.h>
#include <Uranium.h>
#include <Utils/UtilFunctions.h>
#include <Object/BlockObject.h>
#include <Utils/macros.h>
#include <Object/ObjectComponents/BlockComponents/box_breathability.h>
#include <Object/ObjectComponents/BlockComponents/collision_box.h>
#include <Object/ObjectComponents/BlockComponents/crafting_table.h>
#include <Object/ObjectComponents/BlockComponents/destructible_by_explosion.h>
#include <Object/ObjectComponents/BlockComponents/destructible_by_mining.h>
#include <Object/ObjectComponents/BlockComponents/display_name.h>
#include <Object/ObjectComponents/BlockComponents/flammable.h>
#include <Object/ObjectComponents/BlockComponents/friction.h>
#include <Object/ObjectComponents/BlockComponents/geometry.h>
#include <Object/ObjectComponents/BlockComponents/light_dampening.h>
#include <Object/ObjectComponents/BlockComponents/light_emissions.h>
#include <Object/ObjectComponents/BlockComponents/loot.h>
#include <Object/ObjectComponents/BlockComponents/mapColor.h>
#include <Object/ObjectComponents/BlockComponents/materialInstances.h>
#include <Object/ObjectComponents/BlockComponents/queuedTicking.h>

#define TEST_CONSTANT 10
using namespace Uranium::Creation::Components::BlockComponents;

Application::Application() : udk(new Uranium::UraniumDK())
{

	long long* a = new long long(0);
	{
		Uranium::Utils::Timer timer(a);
		for (int i = 0; i < TEST_CONSTANT; i++)
		{
			std::string uuid = Uranium::Utils::CreateUUID();
			auto* block = new Uranium::Creation::BlockObject(uuid.c_str());
			//std::string name = TOKEN_NICE_NAME(block);
			//Uranium::Logs::Logger::Info("Nice Name {}", name);
			// The name doesnt matter so we just allow it to use the default name which is the class name
			block->addComponent <CollisionBox>();
			block->addComponent <CraftingTable>();
			block->addComponent <DestructibleByMining>();
			block->addComponent <DisplayName>();
			block->addComponent <Friction>();
			block->addComponent <Geometry>();
			block->addComponent <lightDampening>();
			block->addComponent <lightEmissions>();
			block->addComponent <Loot>();
			block->addComponent <MapColor>();

			DestructibleByExplosion* destructibleByExplosion = new DestructibleByExplosion(20);
			block->addComponent(destructibleByExplosion);
			Flammable* flammable = new Flammable(20 + i, 40 + i);
			block->addComponent(flammable);
			std::vector<SubClasses::materialInstanceSegment> segments = {
				{
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"*",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						false, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					),
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"up",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						false, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					),
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"down",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						true, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					),
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"north",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						true, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					),
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"east",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						true, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					),
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"south",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						true, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					),
					SubClasses::materialInstanceSegment(
						"texture_name", // Shortname defined in `RP/textures/terrain_textures.json`
						"west",
						true, // Defaults to true; should faces with this material be dimmed by their direction?
						true, // Defaults to true; should shadows be created based on surrounding blocks?
						"blend" // One of the render methods in the above table
					)
				}
			};
			MaterialInstances* materialInstances = new MaterialInstances(segments);
			block->addComponent(materialInstances);
			rapidjson::Document doc;
			block->getAsJsonData(&doc);
			//Uranium::Logs::Logger::Info("Exiting");
			udk->RegisterBlock(block);
		}
	}
	Uranium::Logs::Logger::Info("Average Of {} per block ns or {} ms", long double(*a) / TEST_CONSTANT, (long double(*a) / TEST_CONSTANT) / 1000000);

	{
		//Uranium::Utils::Timer timer("Dumping Registery");
		//udk->DumpRegisteryToTempFolder("C:/Users/pjhnt/Documents/tempBlocks/");
	}
}