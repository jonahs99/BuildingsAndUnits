#include "ECS.h"

Manager::Manager() {

}

Manager::~Manager() {

}

void Manager::init() {
	
}

ComponentMask Manager::generateMask(vector<type_index>& components) {
	ComponentMask mask;
	for (auto comp : components) {
		if (componentBits.find(comp) != componentBits.end())
			mask |= componentBits[comp];
		else
			cout << "Manager::generateMask >> Invalid type, needed component.\n";
	}
	return mask;
}

unsigned int Manager::createEntityHandle() {
	unsigned int handle = 0;
	while (entityMasks[handle].any()) {
		handle++;
		if (handle >= MAX_ENTITIES) {
			cout << "Manager::createEntityHandle >> Max entities reached, overwriting last index.\n";
			return MAX_ENTITIES - 1;
		}
	}
	return handle;
}

void Manager::updateSystemEntityLists(unsigned int ent) {
	for (auto sys : systems) {
		sys.second->checkNewEntity(ent);
	}
}