#pragma once

#include "../../ecs/ECS.h"

struct TranslateComponent {
	float x, y;
};

class TranslateSystem : System {

public :

	void add(TranslateComponent comp);

private :

	std::vector<TranslateComponent> components;

};