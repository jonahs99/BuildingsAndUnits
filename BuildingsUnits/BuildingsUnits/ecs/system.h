#pragma once

#include "defs.h"
#include "ECS.h"

using std::cout;
using std::string;
using std::bitset;
using std::vector;
using std::shared_ptr;
using std::type_index;
using std::map;

using namespace definitions;

class Manager;

class System {

public:

	System(Manager* mng);

	virtual void init() { };

	virtual void update() { };

	virtual ~System() { };

	void checkNewEntity(unsigned int entity);

protected:

	Manager* manager;

	template <class T>
	void addDependency() {
		dependencies.push_back(type_index(typeid(T)));
		componentFilter = manager->generateMask(dependencies);
	};

	virtual void updateEntities() { };

	vector<unsigned int> systemEntities;

private:

	vector<type_index> dependencies;

	ComponentMask componentFilter;

};