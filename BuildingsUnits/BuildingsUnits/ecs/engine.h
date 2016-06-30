#pragma once

#include  <vector>
#include "ECS.h"

class Engine {

public :

	void mainLoop();
	void update();

	void addSystem(System* sys);

private :

	std::vector<System> systems;

};