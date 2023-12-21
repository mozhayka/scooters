#pragma once
#include <string>
#include "structures.h"
#include "generator.h"

struct input
{
	graph g;
	limits lim;
	std::vector<coordinates> position;
};

input parse_json(std::string filename);
input parse_txt(std::string filename);
