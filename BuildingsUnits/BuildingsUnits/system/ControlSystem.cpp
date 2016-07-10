#include "ControlSystem.h"

void ControlSystem::init(AssetLoader * m_loader) {

	addDependency<InputComponent>();
	addDependency<TranslateComponent>();
	addDependency<AnimationComponent>();

	loader = m_loader;

}

void ControlSystem::update() {

	for (auto entity : systemEntities) {

		auto & ic = manager->getComponent<InputComponent>(entity);
		auto & tc = manager->getComponent<TranslateComponent>(entity);
		auto & ac = manager->getComponent<AnimationComponent>(entity);

		float speed = 0.6;
		ac.enable = ic.up || ic.down || ic.left || ic.right;

		if (ic.up) {
			tc.y -= speed;
			ac.sequence = loader->getFrameSequence("up");
		}
		if (ic.down) {
			tc.y += speed;
			ac.sequence = loader->getFrameSequence("down");
		}
		if (ic.left) {
			tc.x -= speed;
			ac.sequence = loader->getFrameSequence("left");
		}
		if (ic.right) {
			tc.x += speed;
			ac.sequence = loader->getFrameSequence("right");
		}

		if (tc.x < 0)
			tc.x += 1280;
		if (tc.y < 0)
			tc.y += 720;
		if (tc.x > 1280)
			tc.x -= 1280;
		if (tc.y > 720)
			tc.y -= 720;

	}

}