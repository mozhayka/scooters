// scooters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "parser.h"
#include "generator.h"

int main()
{
    std::string filename = "C:/Users/mozha/source/repos/scooters/input/data_1.json";
    input i = parse_json(filename);

	path_generator gen(i.g);
	
	auto p = gen.gen_x_times(i.lim.time_left, i.lim.capacity, 1000);

	std::cout << p.gain << std::endl;
	for (size_t i : p.path)
		std::cout << i << ' ';
	std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
