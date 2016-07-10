#include "AssetLoader.h"

void AssetLoader::loadTextures() {

	Tilemap guy_tm;

	auto * texture = SDL_CreateTextureFromSurface(renderer,
		loadSurface("assets/textures/soldier.png"));
	guy_tm.texture = texture;
	
	guy_tm.tile_width = 32; guy_tm.tile_height = 32;
	guy_tm.tiles_wide = 31; guy_tm.tiles_high = 10;

	tilemaps["guy"] = guy_tm;

	sequences["down"] =		FrameSequence{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	sequences["left"] =		FrameSequence{ 31, 32, 33, 34, 35, 36, 37, 38, 39 };
	sequences["right"] =	FrameSequence{ 62, 63, 64, 65, 66, 67, 68, 69, 70 };
	sequences["up"] =		FrameSequence{ 93, 94, 95, 96, 97, 98, 99, 100, 101 };

}

SDL_Surface* AssetLoader::loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	return loadedSurface;
}