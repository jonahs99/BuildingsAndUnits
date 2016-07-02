#pragma once

#include "SDL.h"

#include "../component.h"
#include "../ecs/system.h"

class RenderSystem : public System {

	using System::System;

public :

	void init() override;

	void update() override;

};