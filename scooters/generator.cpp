#include "generator.h"

#include <map>

path_generator::path_generator(graph g) : g(g), r(g) {}

path path_generator::gen(limits lim)
{
	int cur_cap = 0;
	double cur_dist = 0;
	size_t from = 0;

	std::vector<size_t> path;
	path.push_back(from);
	std::vector<bool> used(g.N, false);
	used[from] = true;

	while (cur_cap < lim.capacity)
	{
		size_t to = r.next_v(from, used);
		if (to == -1 || cur_dist + g.dist[from][to] + g.dist[to][0] > lim.time_left)
		{
			return { path, calc_gain(path, lim)};
		}

		path.push_back(to);
		used[to] = true;
		cur_dist += g.dist[from][to];
		cur_cap++;
		from = to;
	}
	return { path, calc_gain(path, lim) };
}

path_generation_result path_generator::gen_x_times(limits lim, int x)
{
	std::map<int, int> cnt;
	auto opt_path = gen(lim);
	for (int _ = 1; _ < x; _++)
	{
		auto path = gen(lim);

		if (path.gain > opt_path.gain)
		{
			opt_path = path;
		}

		cnt[path.gain]++;
	}

	return { opt_path, cnt };
}

int path_generator::calc_gain(std::vector<size_t> path, limits lim)
{
	int gain = 0;
	size_t from = path[0];
	for (size_t to : path)
	{
		gain += g.prio[to] - lim.penalty * g.dist[from][to];
	}
	return gain;
}