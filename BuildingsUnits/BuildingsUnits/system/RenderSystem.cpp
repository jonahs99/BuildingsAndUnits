#include "RenderSystem.h"

void RenderSystem::init(SDL_Renderer* m_renderer) {

	addDependency<TranslateComponent>();
	addDependency<RenderComponent>();

	renderer = m_renderer;

}

void RenderSystem::update() {

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	for (auto entity : systemEntities) {

		auto tc = manager->getComponent<TranslateComponent>(entity);
		auto rc = manager->getComponent<RenderComponent>(entity);

		SDL_Rect rect;
		rect.x = tc.x - rc.size / 2 + 3; rect.y = tc.y - rc.size / 2 + 3;
		rect.w = rc.size; rect.h = rc.size;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		rect.x -= 3; rect.y -= 3;
		SDL_SetRenderDrawColor(renderer, 50, 100, 200, 255);
		SDL_RenderFillRect(renderer, &rect);

	}

	SDL_RenderPresent(renderer);

}