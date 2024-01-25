#include <bits/stdc++.h>
using namespace std;

int row, col, startX, startY, endX, endY;

int	bfs(vector<vector<int>> &map, vector<unordered_set<int>> &adj)
{
	int			curr;
	queue<int>	q;
	unordered_map<int, int>	lv;

	q.push(map[startX][startY]);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (auto adjacnt : adj[curr])
		{
			if (lv[adjacnt] != 0)
				continue;
			q.push(adjacnt);
			lv[adjacnt] = lv[curr] + 1;
			if (adjacnt == map[endX][endY])
				return (lv[adjacnt]);
		}
	}
	return (0);
}

int	main()
{
	cin >> row >> col >> startX >> startY >> endX >> endY;
	startX--; startY--; endX--; endY--;

	vector<vector<int>>	map(row, vector<int>(col));
	vector<unordered_set<int>>	adj(row * col + 1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
			if (j > 0 && map[i][j - 1] != map[i][j])
			{
				adj[map[i][j]].insert(map[i][j - 1]);
				adj[map[i][j - 1]].insert(map[i][j]);
			}
			if (i > 0 && map[i - 1][j] != map[i][j])
			{
				adj[map[i][j]].insert(map[i - 1][j]);
				adj[map[i - 1][j]].insert(map[i][j]);
			}
		}
	}
	cout << bfs(map, adj) << endl;
	return (0);
}
