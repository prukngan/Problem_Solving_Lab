#include <bits/stdc++.h>
using namespace std;

class topological {
	vector<int>	visited;
	vector<int>	recStack;
public:
	list<int>	vertexList;
	topological(int size) : visited(size, false), recStack(size, false) {}

	bool	isCycle(int cur, vector<vector<int>> &graph)
	{
		visited[cur] = true;
		recStack[cur] = true;
		vertexList.push_back(cur);

		for (auto &adj : graph[cur])
		{
			if (visited[adj] == false)
			{
				if (isCycle(adj, graph))
					return (true);
			}
			else if (recStack[adj] == true)
				return (true);
		}
		recStack[cur] = false;
		return (false);
	}
	bool	isTopological(vector<vector<int>> &graph)
	{
		int	size = graph.size();

		for (int cur = 1; cur < size; cur++)
		{
			if (visited[cur] == false)
			{
				if (isCycle(cur, graph) == true)
					return (false);
			}
		}
		return (true);
	}
};

int main()
{
	int	graphNum, vertexNum, edgeNum, vertex1, vertex2;
	set<pair<int, int>>	;

	cin >> vertexNum >> edgeNum;
	vector<int>	indegree(vertexNum + 1, 0);
	topological	topologicalCheck(vertexNum + 1);

	vector<vector<int>> graph(vertexNum + 1);
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> vertex1 >> vertex2;
		graph[vertex1].push_back(vertex2);
		indegree[vertex2]++;
	}

	if (topologicalCheck.isTopological(graph))
	{
		for (auto &vertex : topologicalCheck.vertexList)
			cout << vertex << endl;
	}
	else
		cout << "no" << endl;
    return 0;
}