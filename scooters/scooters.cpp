// scooters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include "parser.h"
#include "output.h"
#include "generator.h"


int main()
{
	std::string PATH = "C:/Users/mozha/source/repos/scooters/";
	int files_cnt = 5;

	for (int i = 1; i <= files_cnt; i++)
	{
		std::string input_file = std::format("{}input/input{}.txt", PATH, i);
		std::string output_file = std::format("{}output/output{}.txt", PATH, i);
		input in = parse_txt(input_file);

		path_generator gen(in.g);
	
		auto ans = gen.gen_x_times(in.lim, 10000);
		save_path(ans, output_file);
		print_path(ans);

		save_path_coordinates(in, ans, std::format("{}output_coordinates/output_coordinates_{}.txt", PATH, i));
	}
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
