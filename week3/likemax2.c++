#include <bits/stdc++.h>
using namespace std;

int	main()
{
	priority_queue<tuple<int, int, int>>	like_sort;//like, no., status
	map<int, int>	like_count;
	int	n, status, like;
	tuple<int,int,int> t;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> like >> status;
		if (like == 1)
			like_count[status]++;
		else if (like == 0)
			like_count[status]--;
		like_sort.push(make_tuple(like_count[status], i, status));
		while (!like_count.empty()
				&& like_count[get<2>(like_sort.top())] != get<0>(like_sort.top()))
			like_sort.pop();
		cout << get<2>(like_sort.top()) << endl;
	}
}