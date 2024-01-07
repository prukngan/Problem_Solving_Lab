#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int			n, x, y, first_pos = 0;

	cin >> n;
	vector<list<int>::iterator>	pt(n + 1);
	list<int>	necklace[n + 1];
	for (int i = 1; i <= n; i++)
	{
		necklace[i].push_back(i);
		pt[i] = necklace[i].begin();
		first_pos += i; 
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		auto	itr = pt[y];
		necklace[y].splice(++itr, necklace[x]);
		first_pos -= x;
	}
	for (auto &val : necklace[first_pos])
		cout << val << ' ';
	return (0);
}