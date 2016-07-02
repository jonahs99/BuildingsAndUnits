#pragma once

#include <bitset>
#include <array>
using std::bitset;
using std::array;

namespace definitions {

	static const unsigned int MAX_COMPONENTS = 10;
	static const unsigned int MAX_ENTITIES = 10000;

	using ComponentMask = bitset<MAX_COMPONENTS>;



}