#pragma once

#include "../ecs/system.h"
#include "../component.h"

class ControlSystem : public System {

	using System::System;

public:

	void init(AssetLoader * m_loader);

	void update();

private:

	AssetLoader * loader;

};