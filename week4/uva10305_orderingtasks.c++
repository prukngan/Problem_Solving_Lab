#include <bits/stdc++.h>
using namespace std;

void	dfs(vector<int> &order, vector<vector<int>> &adjList, vector<bool> &visited, int curr)
{
	visited[curr] = true;
	for (auto adj : adjList[curr])
	{
		if (!visited[adj])
			dfs(order, adjList, visited, adj);
	}
	order.push_back(curr);
}

int	main()
{
	int	n, m, task1, task2;

	while (cin >> n >> m, (n != 0 || m != 0))
	{
		vector<vector<int>>	adjList(n + 1);
		vector<bool>		visited(n + 1, false);
		
		for (int i = 0; i < m; i++)
		{
			cin >> task1 >> task2;
			adjList[task1].push_back(task2);
		}

		vector<int>	order;
		for (int curr = 1; curr <= n; curr++)
		{
			if (!visited[curr])
				dfs(order, adjList, visited, curr);
		}

		for (int i = n - 1; i >= 0; i--)
		{
			cout << order[i];
			if (i > 0)
				cout << ' ';
		}

		cout << '\n';
	}
}