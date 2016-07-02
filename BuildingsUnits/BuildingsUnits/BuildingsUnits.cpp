// BuildingsUnits.cpp : Defines the entry point for the console application.
//

#include "ecs/ecs.h"


int main()
{

	Manager manager;
	manager.init();
	
	manager.addComponentType<int>();

	manager.addComponent<int>(0, 5);

	cout << manager.getComponent<int>(0) << "\n";

	string in = "";
	std::cin >> in;

    return 0;
}