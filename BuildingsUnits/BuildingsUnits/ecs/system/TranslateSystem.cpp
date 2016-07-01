#include "..\system.h"

void TranslateSystem::init() {
	addDependency(type_index(typeid(TranslateComponent)));
}

void TranslateSystem::updateEntities(vector<unsigned int>& entities) {

	for (auto ent : entities) {
		cout << "translate system updating " << ent << "\n";
		manager->translateComponents[ent].x += 0.1;
	}

}