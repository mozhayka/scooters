#include "generator.h"

#include <map>
#include <iostream>

path_generator::path_generator(graph g) : g(g), r(g) {}

path path_generator::gen(double max_dist, int capacity)
{
	int cur_cap = 0;
	double cur_dist = 0;
	size_t from = 0;
	int sum_priority = 0;

	std::vector<size_t> path;
	path.push_back(from);
	std::vector<bool> used(g.N, false);
	used[from] = true;

	while (cur_cap < capacity)
	{
		size_t to = r.next_v(from, used);
		if (to == -1 || cur_dist + g.dist[from][to] + g.dist[to][0] > max_dist)
		{
			return { path, sum_priority };
		}

		path.push_back(to);
		used[to] = true;
		sum_priority += g.prio[to];
		cur_dist += g.dist[from][to];
		cur_cap++;
		from = to;
	}
	return { path, sum_priority };
}

path path_generator::gen_x_times(double max_dist, int capacity, int x)
{
	std::map<int, int> cnt;
	auto opt_path = gen(max_dist, capacity);
	for (int _ = 1; _ < x; _++)
	{
		auto path = gen(max_dist, capacity);

		if (path.gain > opt_path.gain)
		{
			opt_path = path;
		}

		cnt[path.gain]++;
	}

	for (auto& i : cnt)
		std::cout << i.first << ' ' << i.second << std::endl;

	return opt_path;
}

