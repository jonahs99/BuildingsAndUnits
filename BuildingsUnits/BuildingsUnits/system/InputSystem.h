#pragma once

#include "SDL.h"

#include "../component.h"
#include "../ecs/system.h"

class InputSystem : public System {

	using System::System;

public :

	void init();

	bool update();

};