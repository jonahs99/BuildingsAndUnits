#pragma once

#include "SDL.h"

struct Tilemap {

	SDL_Texture* texture;

	int tile_width;
	int tile_height;
	int tiles_wide;
	int tiles_high;

};