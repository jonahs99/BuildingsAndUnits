#include "..\system.h"

void TranslateSystem::init() {
	addDependency(type_index(typeid(TranslateComponent)));
}

void TranslateSystem::update() {

	for (auto ent : systemEntities) {
		cout << "translate system updating " << ent << "\n";
		//manager->getComponent<TranslateComponent> += 0.1;
	}

}