#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int num;
    vector<unordered_set<int>> adj;
	vector<bool>	visited;

    Graph(int n) : num(n), adj(n + 1), visited(num + 1, false){}

    void	addEdge(int a, int b)
	{
        adj[a].insert(b);
        adj[b].insert(a);
    }

	void	DFS(int node)
	{
		visited[node] = true;
		for (auto connect : adj[node])
		{
			if (visited[connect] == false)
				DFS(connect);
		}
	}

	int	countConnected()
	{
		int				count = 0;

		for (int i = 1; i <= num; i++)
		{
			if (visited[i] == false)
			{
				count++;
				DFS(i);
			}
		}
		return (count);
	}
};

int main() 
{
    int num, edge;
    cin >> num >> edge;

    Graph graph(num);
    for (int i = 0; i < edge; ++i)
	{
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }
    cout << graph.countConnected();
    return (0);
}
