#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, point = 0;

	cin >> n;
	int	penguin[n];
	for (int i = 0; i < n; i++)
		cin >> penguin[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
			if (penguin[j] > penguin[i]) point++;
	}
	cout << point;
	return (0);
}