#include "AISystem.h"

using std::rand;

void AISystem::init() {

	addDependency<InputComponent>();
	addDependency<AIComponent>();

}

void AISystem::update() {

	for (auto entity : systemEntities) {

		auto& ic = manager->getComponent<InputComponent>(entity);
		auto& aic = manager->getComponent<AIComponent>(entity);

		aic.phase--;
		if (aic.phase <= 0) {
			aic.phase = aic.wait;
			ic.down = (rand() % 100) < 30;
			ic.left = (rand() % 100) < 30;
			ic.right = (rand() % 100) < 30;
			ic.up = (rand() % 100) < 30;
		}

	}

}