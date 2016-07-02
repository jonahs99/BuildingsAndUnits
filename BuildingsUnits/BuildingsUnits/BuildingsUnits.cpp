// BuildingsUnits.cpp : Defines the entry point for the console application.
//

#include "ecs/ecs.h"
#include "system/RenderSystem.h"
#include "system/InputSystem.h"
#include "system/ControlSystem.h"
#include "component.h"
#include "ui/UI.h"

Manager manager;

void createPlayerEntity() {

	unsigned int playerEntity = manager.createEntityHandle();

	TranslateComponent tc;
	tc.x = 640; tc.y = 360;
	RenderComponent rc;
	rc.size = 32;
	InputComponent ic { false, false, false, false };

	manager.addComponent(playerEntity, tc);
	manager.addComponent(playerEntity, rc);
	manager.addComponent(playerEntity, ic);

}

int main(int argc, char* args[])
{

	UI ui;
	ui.initWindow();

	manager.addComponentType<TranslateComponent>();
	manager.addComponentType<RenderComponent>();
	manager.addComponentType<InputComponent>();

	RenderSystem renderSystem(&manager);
	renderSystem.init(ui.getRenderer());
	manager.addSystem(&renderSystem);

	InputSystem inputSystem(&manager);
	inputSystem.init();
	manager.addSystem(&inputSystem);

	ControlSystem controlSystem(&manager);
	controlSystem.init();
	manager.addSystem(&controlSystem);

	createPlayerEntity();

	bool running = true;

	while (running) {

		running = inputSystem.update();
		controlSystem.update();
		renderSystem.update();

	}

    return 0;

}