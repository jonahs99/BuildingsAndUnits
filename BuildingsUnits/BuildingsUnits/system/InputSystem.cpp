#include "InputSystem.h"

#include <iostream>

void InputSystem::init() {

	addDependency<InputComponent>();

}

bool InputSystem::update() {

	bool running = true;

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.left = true;
				}
				break;
			case SDLK_RIGHT:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.right = true;
				}
				break;
			case SDLK_UP:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.up = true;
				}
				break;
			case SDLK_DOWN:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.down = true;
				}
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.left = false;
				}
				break;
			case SDLK_RIGHT:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.right = false;
				}
				break;
			case SDLK_UP:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.up = false;
				}
				break;
			case SDLK_DOWN:
				for (auto entity : systemEntities) {
					auto& ic = manager->getComponent<InputComponent>(entity);
					ic.down = false;
				}
				break;
			default:
				break;
			}
		}
	}

	return running;

}