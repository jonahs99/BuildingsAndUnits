#pragma once

#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <memory>
#include <typeindex>
#include <map>
#include <array>

#include <boost/any.hpp> 

#include "defs.h"
#include "system.h"

using std::cout;
using std::string;
using std::bitset;
using std::vector;
using std::unique_ptr;
using std::type_index;
using std::map;
using std::array;

using namespace definitions;

class System;

template <class T>
using ComponentArray = array<T, MAX_ENTITIES>;

class Manager {

public:

	map<type_index, ComponentMask> componentBits;

	// Entity Data
	ComponentMask entityMasks[MAX_ENTITIES];

	Manager();

	~Manager();

	void init();

	ComponentMask generateMask(vector<type_index>& components);

	unsigned int createEntityHandle();

	template <class T>
	void addComponentType() {
		ComponentArray<T> componentArray;
		componentArrays[type_index(typeid(T))] = componentArray;
		componentBits[type_index(typeid(T))] = ComponentMask(1);
		componentBits[type_index(typeid(T))] <<= num_components;
		num_components++;
	}

	template <class T>
	void addComponent(unsigned int entity, T component) {
		ComponentArray<T> * componentArray = boost::any_cast<ComponentArray<T>> (&componentArrays[type_index(typeid(T))]);
		(*componentArray)[entity] = component;
		entityMasks[entity] |= componentBits[type_index(typeid(T))];
		updateSystemEntityLists(entity);
	}
	
	template <class T>
	T& getComponent(unsigned int entity) {
		ComponentArray<T> * componentArray = boost::any_cast<ComponentArray<T>> (&componentArrays[type_index(typeid(T))]);
		return (*componentArray)[entity];
	}

	template <class T>
	void addSystem(T* sys) {
		systems[type_index(typeid(T))] = sys;
	}

	template <class T>
	T* getSystem() {
		auto it = systems.find(type_index(typeid(T)));
		if (it != systems.end())
			return dynamic_cast<T*>(it->second);
		return nullptr;
	}

private:

	map<type_index, System*> systems;

	map<type_index, boost::any> componentArrays;
	unsigned int num_components = 0;

	void updateSystemEntityLists(unsigned int ent);

};