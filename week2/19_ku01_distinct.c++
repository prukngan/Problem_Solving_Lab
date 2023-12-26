#include <bits/stdc++.h>
using namespace std;

int	main()
{
	unordered_set<int>	sum_cost;
	int	num, sum;

	cin >> num;
	int	cost[num];
	for (int i = 0; i < num; i++)
		cin >> cost[i];
	for (int i = 0; i < num; i++)
	{
		sum = 0;
		for (int j = i; j < num; j++)
		{
			sum += cost[j];
			sum_cost.insert(sum);
		}
	}
	cout << sum_cost.size();
	return (0);
}