#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, x, y, sum = 0;
	cin >> n;

	vector<list<int>>	necklace[n + 1];
	// vector<list<int>>	pearl[n + 1];
	for (int i = 1; i <= n; i++)
	{
		necklace[i][0].push_back(i);
		sum += i;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		list<int>	pearl = necklace[y];
		pearl.splice(++(necklace[y].begin()), necklace[x]);
		// necklace[y][0].insert(++(necklace[y][0].begin()), necklace[x][0].begin(), necklace[x][0].end());
		// necklace[x] = necklace[x];
		sum -= x;
		cout << "----------------------------------" << '\n';
		for (int j = 1; j <= n; j++)
		{
			for (auto &val : necklace[j][0])
				cout << val << ' ';
			cout << '\n';
		}
	}
	cout << "----------------------------------" << '\n';
	for (auto val : necklace[sum][0])
		cout << val << ' ';
	return (0);
}