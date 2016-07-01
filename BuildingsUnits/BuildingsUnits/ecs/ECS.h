#pragma once

#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <memory>
#include <typeindex>
#include <map>

#include "defs.h"
#include "component.h"
#include "system.h"

using std::cout;
using std::string;
using std::bitset;
using std::vector;
using std::shared_ptr;
using std::type_index;
using std::map;

class TranslateSystem;

using namespace definitions;

class Manager {

public:

	map<type_index, unsigned int> componentBits;

	// Entity Data
	ComponentMask entityMasks[MAX_ENTITIES];
	TranslateComponent translateComponents[MAX_ENTITIES];

	// Systems
	TranslateSystem* translateSystem;

	Manager();

	~Manager();

	void createSystems();

	ComponentMask generateMask(vector<type_index>& components);

	unsigned int createEntityHandle();

};