#include <bits/stdc++.h>
using namespace std;

int	main()
{
	unordered_map <int, int>	like_count;
	int	max_status, n, status;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> status;
		like_count[status]++;
		if (like_count[status] >= like_count[max_status])
			max_status = status;
		cout << max_status << endl;
	}
	return (0);
}