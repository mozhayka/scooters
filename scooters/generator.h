#pragma once
#include "structures.h"
#include "random.h"
#include <map>

struct path_generation_result
{
	path best;
	std::map<int, int> gain_cnt_destribution;
};

class path_generator
{
private:
	graph g;
	random r;

public:
	path_generator(graph g);

	path gen(limits lim);
	path_generation_result gen_x_times(limits lim, int x = 10);

private:
	int calc_gain(std::vector<size_t> path, limits lim);
};

