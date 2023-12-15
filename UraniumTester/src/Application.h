#pragma once
#include <iostream>
#include <Logger/Logger.h>
#include <Uranium.h>

class Application
{
public:
	Application();
	~Application() {
		Uranium::Logs::Logger::close();
	}

	Uranium::UraniumDK* udk;
};

