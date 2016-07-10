#pragma once

#include <map>
#include <string>
#include <vector>

#include "SDL.h"
#include "SDL_Image.h"
#include "Tilemap.h"

using std::map;
using std::string;

using FrameSequence = std::vector<unsigned int>;

class AssetLoader {

public :

	void init(SDL_Renderer * m_renderer) { renderer = m_renderer; }

	void loadTextures();

	Tilemap * getTileMap(string name) { return &tilemaps[name]; }
	FrameSequence * getFrameSequence(string name) { return &sequences[name]; }

private :

	SDL_Renderer * renderer;

	map<string, Tilemap> tilemaps;
	map<string, FrameSequence> sequences;

	SDL_Surface * loadSurface(string path);

};