// PrintPather.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
using std::string;

#include "Vector3d.h"


int main()
{

	const string obj_path = "model.obj";

	Vector3d<double> vec{ 1, 2, 3 };
	Vector3d<double> vec1{ 3, 2, 1 };

	std::cout << (vec + vec1) << std::endl;
	std::cout << vec << std::endl;
	std::cout << vec1 << std::endl;

	while (true) {}

    return 0;
}

