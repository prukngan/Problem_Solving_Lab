#include <bits/stdc++.h>
using namespace std;

int	pointNum, r;

bool	inRadius(int x_cen, int y_cen, int x_adj, int y_adj)
{
	if (sqrt(pow(x_adj - x_cen, 2) + pow(y_adj - y_cen, 2)) <= r)
		return (true);
	return (false);
}

int	bfs(vector<vector<int>> &graph)
{
	int			curr;
	queue<int>	q;
	vector<int>	lv(pointNum, 0);

	q.push(0);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (auto &adj : graph[curr])
		{
			if (lv[adj] != 0)
				continue;
			lv[adj] = lv[curr] + 1;
			if (adj == pointNum - 1)
				return (lv[adj]);
			q.push(adj);
		}
	}
	return (-1);
}

int	main()
{
	int	x, y;

	cin >> pointNum >> r;
	pointNum += 2;
	vector<pair<int, int>>	pointSet;
	vector<vector<int>>		graph(pointNum);

	pointSet.push_back(make_pair(0, 0));
	for (int i = 0; i < pointNum - 2; i++)
	{
		cin >> x >> y;
		pointSet.push_back(make_pair(x, y));
	}
	pointSet.push_back(make_pair(100, 100));

	for (int curr = 0; curr < pointNum - 1; curr++)
	{
		for (int adj = curr + 1; adj < pointNum; adj++)
		{
			if (inRadius(pointSet[curr].first, pointSet[curr].second,
						pointSet[adj].first, pointSet[adj].second))
			{
				graph[curr].push_back(adj);
				graph[adj].push_back(curr);
			}
		}
	}

	cout << bfs(graph) << '\n';
	return (0);
}