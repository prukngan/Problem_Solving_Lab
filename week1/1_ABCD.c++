#include <bits/stdc++.h>

using namespace std;

int	main()
{
	int	n, sum;

	sum = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> n;
		sum += n;
	}
	cout << sum;
	return (0);
}