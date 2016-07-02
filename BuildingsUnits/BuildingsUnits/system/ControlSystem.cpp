#include "ControlSystem.h"

void ControlSystem::init() {

	addDependency<InputComponent>();
	addDependency<TranslateComponent>();

}

void ControlSystem::update() {

	for (auto entity : systemEntities) {

		auto & ic = manager->getComponent<InputComponent>(entity);
		auto & tc = manager->getComponent<TranslateComponent>(entity);

		float speed = 0.05;
		
		if (ic.up)
			tc.y -= speed;
		if (ic.down)
			tc.y += speed;
		if (ic.left)
			tc.x -= speed;
		if (ic.right)
			tc.x += speed;

	}

}