#pragma once

#include "SDL.h"

#include "../component.h"
#include "../ecs/system.h"

class RenderSystem : public System {

	using System::System;

public :

	void init(SDL_Renderer* m_renderer);

	void update();

private :
	SDL_Renderer* renderer;

};