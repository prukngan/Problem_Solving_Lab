#include<bits/stdc++.h>
using namespace std;

int	main()
{
	int	numLease, numGoods;

	cin >> numLease >> numGoods;

	vector<vector<int>>	lease(numLease, vector<int>(3));
	for (int i = 0; i < numLease; i++)
		cin >> lease[i][0] >> lease[i][1] >> lease[i][2];
	
	int maxGoods = 0;
	vector<int>	goods(numGoods);
	for (int i = 0; i < numGoods; i++) {
		cin >> goods[i];
		maxGoods = max(maxGoods, goods[i]);
	}
	int		round, sumGoods, minCost;
	for (int i = 0; i < numLease; i++)
	{
		if (lease[i][2] < maxGoods)
			continue;
		sumGoods = 0;
		round = 1;
		for (int j = 0; j < numGoods; j++)
		{
			sumGoods += goods[j];
			if (lease[i][2] < sumGoods)	{
				round++;
				sumGoods = 0;
				j--;
			}
		}
		if (i == 0)
			minCost = lease[i][0] + round * lease[i][1];
		else
			minCost = min(minCost, lease[i][0] + round * lease[i][1]);
	}

	cout << minCost << '\n';
	
	return (0);
}