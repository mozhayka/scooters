#include "parser.h"
#include <fstream>
#include "json/json.h"

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
