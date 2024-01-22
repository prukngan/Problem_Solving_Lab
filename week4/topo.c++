#include <bits/stdc++.h>
using namespace std;

class Graph {
	int vertexNum;
	vector<vector<int>>	graph;
	vector<int> indegree;
public:
	Graph(int vertexNum) : vertexNum(vertexNum), graph(vertexNum + 1), indegree(vertexNum + 1, 0) {}

	void	addEgde(int vertex1, int vertex2)
	{
		graph[vertex1].push_back(vertex2);
		indegree[vertex2]++;
	}

	vector<int>	topologicalSort()
	{
		int cur;
		vector<int>	result;
		queue<int>	qZero;

		for (int i = 1; i <= vertexNum; i++)
		{
			if (indegree[i] == 0)
				qZero.push(i);
		}
		while (!qZero.empty())
		{
			cur = qZero.front();
			qZero.pop();
			result.push_back(cur);
			for (auto &adj : graph[cur])
			{
				indegree[adj]--;
				if (indegree[adj] == 0)
					qZero.push(adj);
			}
		}
		if (result.size() != vertexNum)
			return (vector<int>());
		return (result);
	}
};

int	main()
{
	int	vertexNum, edgeNum;
	int	vertex1, vertex2;

	cin >> vertexNum >> edgeNum;

	Graph	graph(vertexNum);

	for (int i = 0; i < edgeNum; i++)
	{
		cin >> vertex1 >> vertex2;
		graph.addEgde(vertex1, vertex2);
	}

	vector<int>	result = graph.topologicalSort();
	if (result.empty())
	{
		cout << "no" << endl;
		return (0);
	}
	for (auto &val : result)
		cout << val << endl;
	return (0);
}