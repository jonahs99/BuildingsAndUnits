#pragma once

#include <bitset>
using std::bitset;

namespace definitions {
	static const unsigned int NUM_COMPONENTS = 10;
	static const unsigned int MAX_ENTITIES = 5000;
	using ComponentMask = bitset<NUM_COMPONENTS>;
}