#pragma once

#include "sdl.h"

class UI {

public:

	void initWindow();

	SDL_Renderer* getRenderer() { return renderer; };


private:
	SDL_Window* window;
	SDL_Renderer* renderer;

};