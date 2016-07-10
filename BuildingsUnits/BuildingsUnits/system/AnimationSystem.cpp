#include "AnimationSystem.h"

void AnimationSystem::init() {
	addDependency<RenderComponent>();
	addDependency<AnimationComponent>();
}

void AnimationSystem::update() {

	for (auto entity : systemEntities) {

		auto& rc = manager->getComponent<RenderComponent>(entity);
		auto& ac = manager->getComponent<AnimationComponent>(entity);

		if (ac.enable) {
			ac.phase--;
			if (ac.phase <= 0) {
				ac.phase = ac.wait;
				ac.frame++;
				ac.frame %= ac.sequence->size();
				rc.tileIndex = (*ac.sequence)[ac.frame];
			}
		}

	}

}