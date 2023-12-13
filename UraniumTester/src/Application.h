#pragma once
#include <iostream>
#include <Logger/Logger.h>

class Application
{
public:
	Application();
	~Application() {
		Uranium::Logs::Logger::close();
	}
};

