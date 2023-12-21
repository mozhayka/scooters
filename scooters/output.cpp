#include "parser.h"
#include <fstream>
#include "json/json.h"
#include <iostream>

void print_path(path p)
{
	std::cout << p.vertices.size() - 1 << std::endl;
	for (size_t i = 1; i < p.vertices.size(); i++)
		std::cout << p.vertices[i] << ' ';
	std::cout << std::endl;
}

void print_path_with_gain(path p)
{
	std::cout << p.gain << std::endl;
	for (size_t i : p.vertices)
		std::cout << i << ' ';
	std::cout << std::endl;
}

void save_path(path p, std::string output)
{
	std::ofstream out(output);
	if (!out)
		throw new std::runtime_error("Cannot open file " + output);

	out << p.vertices.size() - 1 << std::endl;
	for (size_t i = 1; i < p.vertices.size(); i++)
		out << p.vertices[i] << ' ';
	out << std::endl;
}