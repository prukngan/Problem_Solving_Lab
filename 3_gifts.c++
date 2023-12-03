#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, val, sum;

	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		if (val > 0)
			sum += val;
	}
	cout << sum;
	return (0);
}