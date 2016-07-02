#include "system.h"

System::System(Manager* mng) {
	manager = mng;
}

void System::checkNewEntity(unsigned int ent) {
	if ((manager->entityMasks[ent] & componentFilter) == componentFilter) {
		systemEntities.push_back(ent);
	}
}

void System::addDependency(type_index componentType) {
	dependencies.push_back(componentType);
	componentFilter = manager->generateMask(dependencies);
}