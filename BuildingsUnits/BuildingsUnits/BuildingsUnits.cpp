// BuildingsUnits.cpp : Defines the entry point for the console application.
//

#include "ecs/Manager.h"
#include "system/RenderSystem.h"
#include "system/AnimationSystem.h"
#include "system/InputSystem.h"
#include "system/ControlSystem.h"
#include "system/AISystem.h"
#include "component.h"
#include "ui/UI.h"
#include "gfx/AssetLoader.h"

Manager manager;
AssetLoader loader;

void createPlayerEntity() {

	unsigned int playerEntity = manager.createEntityHandle();

	TranslateComponent tc;
	tc.x = 640; tc.y = 360;
	RenderComponent rc;
	rc.tilemap = loader.getTileMap("guy");
	rc.tileIndex = 0;
	InputComponent ic { false, false, false, false };
	AnimationComponent ac;
	ac.phase = 0; ac.wait = 4;
	ac.frame = 0; ac.enable = false;
	ac.sequence = loader.getFrameSequence("down");
	AIComponent aic;
	aic.phase = std::rand() % 50; aic.wait = 200 + std::rand() % 40;

	manager.addComponent(playerEntity, tc);
	manager.addComponent(playerEntity, rc);
	manager.addComponent(playerEntity, ic);
	manager.addComponent(playerEntity, ac);
	manager.addComponent(playerEntity, aic);

}

int main(int argc, char* args[])
{

	UI ui;
	ui.initWindow();

	manager.addComponentType<TranslateComponent>();
	manager.addComponentType<RenderComponent>();
	manager.addComponentType<AnimationComponent>();
	manager.addComponentType<InputComponent>();
	manager.addComponentType<AIComponent>();

	RenderSystem renderSystem(&manager);
	renderSystem.init(ui.getRenderer());
	manager.addSystem(&renderSystem);

	AnimationSystem animationSystem(&manager);
	animationSystem.init();
	manager.addSystem(&animationSystem);

	InputSystem inputSystem(&manager);
	inputSystem.init();
	manager.addSystem(&inputSystem);

	ControlSystem controlSystem(&manager);
	controlSystem.init(&loader);
	manager.addSystem(&controlSystem);

	AISystem aiSystem(&manager);
	aiSystem.init();
	manager.addSystem(&aiSystem);

	loader.init(ui.getRenderer());
	loader.loadTextures();

	for (int i = 0; i < 40; i++) {
		createPlayerEntity();
		manager.getComponent<TranslateComponent>(manager.createEntityHandle() - 1).x = (i % 10) * 100 + 140;
		manager.getComponent<TranslateComponent>(manager.createEntityHandle() - 1).y = (i / 10) * 100 + 300;
	}

	int MS_PER_UPDATE = 33;

	int previous = SDL_GetTicks();
	int lag = 0;

	bool updated = true;
	bool running = true;
	while (running) {
		int current = SDL_GetTicks();
		int ellapsed = current - previous;
		previous = current;
		lag += ellapsed;

		running = inputSystem.update();

		while (lag >= MS_PER_UPDATE) {
			int updatemeasure = SDL_GetTicks();
			aiSystem.update();
			controlSystem.update();
			animationSystem.update();
			cout << "Updating in " << (SDL_GetTicks() - updatemeasure) << " ms. \n";
			lag -= MS_PER_UPDATE;
			updated = true;
		}

		if (updated) {
			int rendermeasure = SDL_GetTicks();
			renderSystem.update();
			updated = false;
			cout << "Rendering in " << (SDL_GetTicks() - rendermeasure) << " ms. \n";
		}

	}

    return 0;

}