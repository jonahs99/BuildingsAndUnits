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

	void update();

	virtual ~System() { };

protected:

	Manager* manager;

	void addDependency(type_index componentType);

	virtual void updateEntities(vector<unsigned int>& entities) { };

private:

	vector<type_index> dependencies;

	ComponentMask componentFilter;

};

class TranslateSystem : System {

	void init() override;

	void updateEntities(vector<unsigned int>& entities) override;

};