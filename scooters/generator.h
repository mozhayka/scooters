#pragma once
#include "structures.h"
#include "random.h"

class path_generator
{
private:
	graph g;
	random r;

public:
	path_generator(graph g);

	path gen(double max_dist, int capacity);
	path gen_x_times(double max_dist, int capacity, int x = 10);
};

