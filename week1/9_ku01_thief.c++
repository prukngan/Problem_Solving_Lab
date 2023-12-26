#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, K, T;
	int	i, n;
	int	*group;

	cin >> N >> K >> T;
	group = (int*)calloc(N, sizeof(int));
	n = i = 1;
	group[i] = 1;
	do
	{
		i = (i + K) % N;
		if (group[i] != 1)
		{
			group[i] = 1;
			n++;
		}
	}
	while (i != 1 && i != T);
	cout << n;
	free(group);
	return (0);
}
