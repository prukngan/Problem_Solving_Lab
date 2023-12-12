#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, x, y, sum = 0;
	cin >> n;

	list<int>	necklace[n + 1];
	for (int i = 1; i <= n; i++)
	{
		necklace[i].push_front(i);
		sum += i;
	} 
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		necklace[y].insert(++(necklace[y].begin()), necklace[x].begin(), necklace[x].   end());
		sum -= x;
		// cout << "----------------------------------" << '\n';
		// for (int j = 1; j <= n; j++)
		// {
		// 	for (auto &val : necklace[j])
		// 		cout << val << ' ';
		// 	cout << '\n';
		// }
	}
	// cout << "----------------------------------" << '\n';
	list<int>	head = necklace[sum];
	for (auto &iter1 : head)
	{
		if (iter1 != sum)
		{
			for (auto &iter2 : necklace[iter1])
			{
				if (iter2 != necklace[iter1].back())
					cout << iter2 << ' ';
			}
		}
		else
			cout << sum << ' ';
	}
	cout << necklace[head.back()].back();
	return (0);
}