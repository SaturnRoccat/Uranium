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


Application::Application() : dk(new Uranium::UraniumDK())
{
	auto* block = new Uranium::Creation::BlockObject("current_test_block");

	std::string name = TOKEN_NICE_NAME(block);
	Uranium::Logs::Logger::Info("Nice Name {}", name);
	// The name doesnt matter so we just allow it to use the default name which is the class name
	block->addComponent <Uranium::Creation::Components::BlockComponents::box_breathability> ();
	block->addComponent <Uranium::Creation::Components::BlockComponents::CollisionBox> ();
	block->addComponent <Uranium::Creation::Components::BlockComponents::CraftingTable> ();
	block->addComponent <Uranium::Creation::Components::BlockComponents::DestructibleByMining> ();
	block->addComponent <Uranium::Creation::Components::BlockComponents::DisplayName> ();

	Uranium::Creation::Components::BlockComponents::DestructibleByExplosion* destructibleByExplosion = new Uranium::Creation::Components::BlockComponents::DestructibleByExplosion(20);
	block->addComponent(destructibleByExplosion);
	Uranium::Creation::Components::BlockComponents::Flammable* flammable = new Uranium::Creation::Components::BlockComponents::Flammable(20, 40);
	block->addComponent(flammable);
	rapidjson::Document doc;
	block->getAsJsonData(&doc);
	Uranium::Logs::Logger::Info("Exiting");
}