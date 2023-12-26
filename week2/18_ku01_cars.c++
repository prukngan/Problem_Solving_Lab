#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, cost, efficacy, max, out = 0;

	cin >> n;
	int	collect[n];
	for (int i = 0; i < n; i++)
	{
		cin >> cost >> efficacy;
		collect[i] = efficacy;
	}
	max = collect[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (collect[i] <= max)
			out++;
		else
			max = collect[i];
	}
	cout << out;
	return (0);
}