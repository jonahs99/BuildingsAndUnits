#pragma once

#include <map>
#include <string>

#include "SDL.h"
#include "Tilemap.h"

using std::map;
using std::string;

class TextureLoader {

public :

	void loadTextures();

	Tilemap* getTileMap(string name) { return tilemaps[name]; }

private :

	map<string, Tilemap*> tilemaps;

};