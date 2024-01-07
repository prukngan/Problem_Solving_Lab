#include <bits/stdc++.h>
using namespace std;

class bipartite {
public:
    bool	check(int cur, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int>	q;

        q.push(cur);
        color[cur] = 0;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            for(auto adj : graph[cur])
            {
                if (color[adj] == -1)
                {
                    color[adj] = !color[cur];
                    q.push(adj);
                }
                else if (color[adj] == color[cur])
					return (false);
            }
        }
        return (true);
    }
    bool	isBipartite(vector<vector<int>> &graph)
	{
        int	n = graph.size();

        vector<int>	color(n, -1);
        for(int i = 1; i < n; i++)
        {
            if(color[i] == -1 && check(i,graph,color) == false)
				return (false);
        }
        return (true);
    }
};

int main()
{
	bipartite	bipartiteCheck;
	int	graphNum, curNum, edgeNum, cur1, cur2;

	cin >> graphNum;
	for (int i = 0; i < graphNum; ++i)
	{
		cin >> curNum >> edgeNum;
    	vector<vector<int>> graph(curNum + 1);
		for (int j = 0; j < edgeNum; ++j)
		{
			cin >> cur1 >> cur2;
			graph[cur1].push_back(cur2);
			graph[cur2].push_back(cur1);
		}
		(bipartiteCheck.isBipartite(graph)) ? cout << "yes" : cout << "no";  cout << endl;
    }
    return 0;
}
