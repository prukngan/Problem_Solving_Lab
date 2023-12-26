#include <bits/stdc++.h>
using namespace std;

int	main()
{
	unordered_map<int, long>	warehouse;
	int	num, n, a, b;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		if (n == 1)
		{
			cin >> a >> b;
			warehouse[a] += b;
		}
		else if (n == 2)
		{
			cin >> a;
			cout << warehouse[a] << endl;
		}
		else if (n == 3)
		{
			cin >> a >> b;
			if (warehouse[a] < b)
			{
				cout << warehouse[a] << endl;
				b = warehouse[a];
			}
			else
				cout << b << endl;
			warehouse[a] -= b;
		}
	}
	return (0);
}