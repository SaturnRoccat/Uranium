#include "Application.h"
#include <Logger/Logger.h>
#include <Uranium.h>
#include <Utils/UtilFunctions.h>
#include <Object/BlockObject.h>
#include <Utils/macros.h>


Application::Application()
{
	auto* block = new Uranium::Creation::BlockObject("TestBlock");

	std::string name = TOKEN_NICE_NAME(block);
	Uranium::Logs::Logger::Info("Nice Name {}", name);
}