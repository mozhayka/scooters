#include "parser.h"
#include <fstream>
#include "json/json.h"
#include <iostream>

input parse_json(std::string filename)
{
	std::ifstream in(filename);
	if (!in)
		throw new std::runtime_error("Cannot open file " + filename);

	Json::Value data;
	in >> data;

	int n = data["points"].size();
	std::vector<int> prio(n, 0);
	std::vector<std::vector<int>> dist(n, std::vector<int>(n, 0));
	std::vector<coordinates> position(n);

	for (int i = 0; i < data["points"].size(); i++)
	{
		auto& point = data["points"][i];
		prio[i] = point["priority"].asInt();
		position[i] = { point["position"][0].asDouble(), point["position"][1].asDouble() };
	}

	for (int from = 0; from < data["time_matrix"].size(); from++)
	{
		for (int to = 0; to < data["time_matrix"].size(); to++)
		{
			dist[from][to] = data["time_matrix"][from][to].asInt();
		}
	}

	graph g = {
		n,
		prio,
		dist
	};

	limits lim = {
		data["capacity"].asInt(),
		data["time_left"].asInt(),
		data["penalty"].asInt(),
	};

	return {g, lim, position};
}

void print_path(path p)
{
	std::cout << p.gain << std::endl;
	for (size_t i : p.path)
		std::cout << i << ' ';
	std::cout << std::endl;
}

void print_destribution(std::map<int, int> d)
{
	for (auto& i : d)
		std::cout << i.first << ' ' << i.second << std::endl;
}

void print(path_generation_result result)
{
	print_path(result.best);
	print_destribution(result.gain_cnt_destribution);
}