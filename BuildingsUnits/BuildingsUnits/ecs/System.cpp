#include "system.h"

System::System(Manager* mng) {
	manager = mng;
}

void System::update() {
	vector<unsigned int> matchingEntities;
	for (int entity = 0; entity < MAX_ENTITIES; entity++) {
		if ((manager->entityMasks[entity] & componentFilter) == componentFilter) {
			matchingEntities.push_back(entity);
		}
	}
	updateEntities(matchingEntities);
}

void System::addDependency(type_index componentType) {
	dependencies.push_back(componentType);
	componentFilter = manager->generateMask(dependencies);
}