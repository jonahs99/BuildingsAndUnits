#include "stdafx.h"

#include "engine.h"

void Engine::mainLoop() {
	//	Todo: add timestepping
}

void Engine::update() {
	for (auto sys : systems) {
		sys.update();
	}
}

void Engine::addSystem(System* sys) {
	systems.push_back(*sys);
}