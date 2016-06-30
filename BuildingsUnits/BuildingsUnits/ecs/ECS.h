#pragma once

#include <bitset>
#include <vector>
#include <string>
#include <memory>
using std::string;
using std::bitset;
using std::vector;
using std::shared_ptr;


class Component;
class System;
class Manager;

struct Entity {
	unsigned int id;
};

class Component {
	
};

class System {

public :

	virtual void init() { };

	void update() {
		
		vector<unsigned int> matchingEntities;

		for (int entity = 0; entity < Manager::MAX_ENTITIES; entity++) {
			if ((manager->entityMasks[entity] & componentFilter) == componentFilter) {
				matchingEntities.push_back(entity);
			}
		}

		updateEntities(matchingEntities);
	
	};

	virtual ~System() { };

private :

	shared_ptr<Manager> manager;

	bitset<Manager::NUM_COMPONENTS> componentFilter;

	virtual void updateEntities(vector<unsigned int>& entities) { };

};

class Manager {

public :

	static const unsigned int NUM_COMPONENTS = 10;
	static const unsigned int MAX_ENTITIES = 5000;

	bitset<NUM_COMPONENTS> entityMasks[MAX_ENTITIES];

	Manager() {
		thisPointer = shared_ptr<Manager>(this);
	}

private :

	static const unsigned int NUM_COMPONENTS;

	shared_ptr<Manager> thisPointer;

};