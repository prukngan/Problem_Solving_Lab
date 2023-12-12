#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int		map[2] = {0, 0};
	char	d[100];

	cin >> d;
	for (int i = 0; d[i] != '\0'; i++)
	{
		if (d[i] == 'N') map[1]++;
		else if (d[i] == 'S') map[1]--;
		else if (d[i] == 'E') map[0]++;
		else if (d[i] == 'W') map[0]--;
		else if (d[i] == 'Z') map[0] = map[1] = 0;
	}
	cout << map[0] << " " << map[1];
}