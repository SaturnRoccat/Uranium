#include "Application.h"
#include <Logger/Logger.h>
#include <Uranium.h>
#include <Utils/UtilFunctions.h>
#include <Object/BlockObject.h>
#include <Utils/macros.h>
#include <Object/ObjectComponents/BlockComponents/box_breathability.h>
#include <Object/ObjectComponents/BlockComponents/collision_box.h>
#include <Object/ObjectComponents/BlockComponents/crafting_table.h>


Application::Application() : dk(new Uranium::UraniumDK())
{
	auto* block = new Uranium::Creation::BlockObject("current_test_block");

	std::string name = TOKEN_NICE_NAME(block);
	Uranium::Logs::Logger::Info("Nice Name {}", name);
	// The name doesnt matter so we just allow it to use the default name which is the class name
	block->addComponent <Uranium::Creation::Components::BlockComponents::box_breathability> ();
	block->addComponent <Uranium::Creation::Components::BlockComponents::CollisionBox> ();
	block->addComponent <Uranium::Creation::Components::BlockComponents::CraftingTable> ();
	rapidjson::Document doc;
	block->getAsJsonData(&doc);
	Uranium::Logs::Logger::Info("Exiting");
}