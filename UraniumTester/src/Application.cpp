#include "Application.h"
#include <Logger/Logger.h>
#include <Uranium.h>
#include <Utils/UtilFunctions.h>
#include <Object/BlockObject.h>
#include <Utils/macros.h>


Application::Application()
{
	auto* block = new Uranium::Creation::BlockObject("TestBlock");
	// Q: Why is this throwing C++ expression must have integral or unscoped enum type?
	// A: Because you're trying to add a string to a const char*.

	// std::string name = std::string("block") + " (" + DemangleMSVCName(typeid(block).name()).c_str() + ")";
	std::string name = TOKEN_NICE_NAME(block);
	Uranium::Logs::Logger::Info("Nice Name {}", name);
}