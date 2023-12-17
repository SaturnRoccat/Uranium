#include "Application.h"
#include <Logger/Logger.h>
#include <Uranium.h>
#include <Utils/UtilFunctions.h>
#include <Object/BlockObject.h>
#include <Utils/macros.h>
#include <blocks.h>

using namespace Uranium::Creation::Components::BlockComponents;

Application::Application() : udk(new Uranium::UraniumDK())
{

	auto* uraniumBlock = new Uranium::Creation::BlockObject("uranium_block");

	uraniumBlock->addComponent<CollisionBox>();
	uraniumBlock->addComponent(new DisplayName("Uranium Block"));
	uraniumBlock->addComponent(new DestructibleByMining(3.f));

	udk->RegisterBlock(uraniumBlock);

	rapidjson::Document doc;
	uraniumBlock->getAsJsonData(&doc);


}