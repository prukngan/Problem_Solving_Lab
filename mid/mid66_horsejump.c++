#include <bits/stdc++.h>
using namespace std;

int row;

vector<pair<int, int>>	jump = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
								{1, 2}, {2, 1}, {2, -1}, {1, -2}};
vector<pair<int, int>>	walk = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool	isValid(int x, int y, vector<string> &map)
{
	if ((x < 0 || x >= row) || (y < 0 || y >= row))
		return (false);
	if (map[x][y] == '#')
		return (false);
	return (true);
}

int	bfs2(vector<string> &map, vector<vector<int>> &pathToEnd)
{
	int						minPath = row * row;
	queue<pair<int, int>>	q;
	pair<int, int>			curr;
	vector<vector<int>>		startPath(row, vector<int>(row));

	q.push(make_pair(0, 0));
	startPath[0][0] = 0;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (auto jumpPoint : jump)
		{
			int x_jump = curr.first + jumpPoint.first;
			int y_jump = curr.second + jumpPoint.second;
			if (isValid(x_jump, y_jump, map) && pathToEnd[x_jump][y_jump] != 0)
				minPath = min(minPath, startPath[curr.first][curr.second] + pathToEnd[x_jump][y_jump]);
		}
		for (auto walkPoint : walk)
		{
			int x_adj = curr.first + walkPoint.first;
			int y_adj = curr.second + walkPoint.second;
			if (isValid(x_adj, y_adj, map) == false || startPath[x_adj][y_adj] != 0)
				continue;
			startPath[x_adj][y_adj] = startPath[curr.first][curr.second] + 1;
			q.push(make_pair(x_adj, y_adj));
		}
	}
	return (min(minPath, startPath[row - 1][row - 1]));
}

int	bfs(vector<string> &map)
{
	pair<int, int>			curr;
	queue<pair<int, int>>	q;
	vector<vector<int>>		pathToEnd(row, vector<int>(row));

	q.push(make_pair(row - 1, row - 1));
	pathToEnd[row - 1][row - 1] = 1;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (auto walkPoint : walk)
		{
			int x_adj = curr.first + walkPoint.first;
			int y_adj = curr.second + walkPoint.second;
			if (isValid(x_adj, y_adj, map) == false || pathToEnd[x_adj][y_adj] != 0)
				continue;
			pathToEnd[x_adj][y_adj] = pathToEnd[curr.first][curr.second] + 1;
			q.push(make_pair(x_adj, y_adj));
		}
	}
	return (bfs2(map, pathToEnd));
}

int	main()
{
	cin >> row;

	vector<string>	map(row + 1);
	for (int i = 0; i < row; i++)
		cin >> map[i];
	cout << bfs(map) << endl;
	return (0);
}