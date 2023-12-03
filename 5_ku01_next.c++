#include <bits/stdc++.h>
using namespace std;

int	count_round(const int *next, int num)
{
	int	check[num];
	int	max, round, i, n;

	for (int i = 1; i <= num; i++)
	{
		n = i;
		round = 0;
		while (check[n] != 1)
		{
			round++;
			check[n] = 1;
			n = next[n];
		}
		if (round > max) max = round;
	}
	return (max);
}

int	main()
{
	int *next;
	int	num, n;

	cin >> num;
	next = (int*)malloc(sizeof(int) * (num + 1));
	if (next == NULL)
		return (-1);
	for (int i = 1; i <= num; i++)
	{
		cin >> n;
		next[i] = n;
	}
	cout << count_round(next, num);
	return (0);
}