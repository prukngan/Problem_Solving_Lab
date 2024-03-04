#include <bits/stdc++.h>
using namespace std;

int	nodeNum, edgeNum;

void	dijkstra(int u, vector<vector<pair<int, int>>> &graph)
{
	set<pair<int, int>>	q;
	vector<int>			visited(nodeNum, false);
	vector<int>			dis(nodeNum, INT_MAX);

	dis[u] = 0;
	q.insert({dis[u], u});
	while (!q.empty())
	{
		u = (*(q.begin())).second;
		q.erase(q.begin());
		if (visited[u] == true)
			continue;

		visited[u] = true;
		for (auto &adj : graph[u])
		{
			int	v = adj.first;
			int weight = adj.second;

			if (dis[u] + weight < dis[v])
			{
				dis[v] = dis[u] + weight;
				q.insert({dis[v], v});
			}
		}
	}
	cout << dis[nodeNum - 1] << '\n';
}

int	main()
{
	int	node1, node2, w;

	cin >> nodeNum >> edgeNum;
	vector<vector<pair<int, int>>>	graph(nodeNum);
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> node1 >> node2 >> w;
		node1--; node2--;
		graph[node1].push_back({node2, w});
		graph[node2].push_back({node1, w});
	}
	dijkstra(0, graph);
	return (0);
}