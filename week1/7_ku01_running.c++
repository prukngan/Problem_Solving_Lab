#include <bits/stdc++.h>
using namespace std;

int	main()
{
	long	n, k, fastest;
	int		count = 0;

	cin >> n >> k;
	int	runner[n];
	for (int i = 0; i < n; i++)
	{
		cin >> runner[i];
		if (runner[i] < fastest || i == 0) fastest = runner[i];
	}
	for (int i = 0; i < n; i++)
		if ((runner[i] - fastest) * (k - 1) <= fastest) count++;
	cout << count;
	return (0);
}
