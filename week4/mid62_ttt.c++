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

int	main()
{
	bipartite	bipartiteCheck;
	int	employNum, historyNum;

	cin >> employNum >> historyNum;
	vector<pair<int, int>>	history(historyNum);

	for (int i = 0; i < historyNum; i++)
		cin >> history[i].first >> history[i].second;

	for (int i = 0; i < historyNum; i++)
	{
		vector<vector<int>>	graph(historyNum + 1);
		for (int j = 0; j < historyNum; j++)
		{
			if (i == j)
				continue;
			graph[history[j].first].push_back(history[j].second);
			graph[history[j].second].push_back(history[j].first);
		}
		if (bipartiteCheck.isBipartite(graph) == true)
		{
			cout << history[i].first << ' ' << history[i].second << endl;
			return (0);
		}
	}
	return (0);
}