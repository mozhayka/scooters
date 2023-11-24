#pragma once
#include <string>
#include "structures.h"
#include "generator.h"

input parse_json(std::string filename);
void print_path(path p);
void print_destribution(std::map<int, int> d);
void print(path_generation_result result);