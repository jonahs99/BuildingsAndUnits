#include "RenderSystem.h"

void RenderSystem::init() {

	addDependency<TranslateComponent>();
	addDependency<RenderComponent>();

}

void RenderSystem::update() {



}