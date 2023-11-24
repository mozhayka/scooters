#pragma once
#include <vector>

struct graph
{
	size_t N;

	std::vector<int> prio;
	std::vector<std::vector<int>> dist;
};

struct limits
{
	int capacity;
	int time_left;
	int penalty;
};

struct coordinates
{
	double x, y;
};

struct input
{
	graph g;
	limits lim;
	std::vector<coordinates> position;
};

struct path
{
	std::vector<size_t> path;
	int gain;
};