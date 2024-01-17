#include "parser.h"
#include <fstream>
#include "json/json.h"
#include <iostream>


void print_path(path p)
{
	std::cout << p.vertices.size() << " gain: " << p.gain << std::endl;
	for (size_t i : p.vertices)
		std::cout << i << ' ';
	std::cout << std::endl;
}

void save_path(path p, std::string output)
{
	std::ofstream out(output);
	if (!out)
		throw new std::runtime_error("Cannot open file " + output);

	out << p.vertices.size() << std::endl;
	for (size_t i = 0; i < p.vertices.size(); i++)
		out << p.vertices[i] << ' ';
	out << std::endl;
}

void save_path_coordinates(input inp, path p, std::string output)
{
	std::ofstream out(output);
	if (!out)
		throw new std::runtime_error("Cannot open file " + output);

	out << inp.position[0].x << ' ' << inp.position[0].y << " " << 0 << std::endl;
	for (size_t i = 0; i < p.vertices.size(); i++)
		out << inp.position[p.vertices[i]].x << ' ' << inp.position[p.vertices[i]].y << " " << p.vertices[i] << std::endl;
}
