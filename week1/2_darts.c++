#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	num, dis, x, y, score;

	cin >> num;
	score = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		dis = ceil(sqrt(x*x + y*y));
		if (dis <= 2)
			score += 5;
		else if (dis <= 4)
			score += 4;
		else if (dis <= 6)
			score += 3;
		else if (dis <= 8)
			score += 2;
		else if (dis <= 10)
			score += 1;
		else
			score += 0;
	}
	cout << score;
	return (0);
}