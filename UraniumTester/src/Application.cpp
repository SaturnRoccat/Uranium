#include "Application.h"
#include <Logger/Logger.h>
#include <Uranium.h>
#include <Utils/UtilFunctions.h>
#include <Object/BlockObject.h>


Application::Application()
{
	auto* block = new Uranium::Creation::BlockObject("TestBlock");
	Uranium::Logs::Logger::Info("Created BlockObject: {}", block->objectData);
}