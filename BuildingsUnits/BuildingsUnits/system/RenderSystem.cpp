#include "RenderSystem.h"

#include <algorithm>

void RenderSystem::init(SDL_Renderer* m_renderer) {

	addDependency<TranslateComponent>();
	addDependency<RenderComponent>();

	renderer = m_renderer;

}

void RenderSystem::update() {

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	for (auto entity : systemEntities) {

		auto& tc = manager->getComponent<TranslateComponent>(entity);
		auto& rc = manager->getComponent<RenderComponent>(entity);
		auto * tilemap = rc.tilemap;

		SDL_Rect drect;
		drect.x = tc.x - tilemap->tile_width; drect.y = tc.y - tilemap->tile_height;
		drect.w = tilemap->tile_width * 4; drect.h = tilemap->tile_height * 4;

		SDL_Rect srect;
		srect.x = (rc.tileIndex % tilemap->tiles_wide) * tilemap->tile_width;
		srect.y = (rc.tileIndex / tilemap->tiles_wide) * tilemap->tile_height;
		srect.w = tilemap->tile_width; srect.h = tilemap->tile_height;

		SDL_RenderCopy(renderer, tilemap->texture, &srect, &drect);

	}

	SDL_RenderPresent(renderer);

}