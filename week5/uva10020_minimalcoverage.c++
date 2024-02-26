#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int	l, r, m;
		// int	max_r = -1, min_l = m + 1;

		cin >> m;
		list<pair<int, int>>	lines;
		pair<int, int>	leftPair = {0, -1}, rightPair = {m + 1, 0};
		while (cin >> l >> r, l || r)
		{
			if (l <= 0) // left case
			{
				if (r > leftPair.second) {
					leftPair = {l, r};
				}
			}
			else if (r >= m) // right case
			{
				if (l < rightPair.first) {
					rightPair = {l, r};
				}
			}
			else
				lines.push_back(make_pair(l, r));
		}

		int	start = leftPair.second, end = rightPair.first;
		if (!lines.empty() && start < end)
		{
			sort(lines.begin(), lines.end());
			
			// max_r = min_l = 0;
			for (auto sec = lines.begin(); sec != lines.end();)
			{
				if (sec->first <= start && sec->second > start) {
					start = sec->second;
					++sec;
				} else {
					sec = lines.erase(sec);
				}
			}
		}

		if (start < end && leftPair.second == -1 && rightPair.first == m + 1)
			cout << 0;
		else
		{
			cout << lines.size() << '\n';
			cout << leftPair.first << ' ' << leftPair.second << '\n';
			for (auto &sec : lines)
				cout << sec.first << ' ' << sec.second << '\n';
			cout << rightPair.first << ' ' << rightPair.second << '\n';
		}
		cout << '\n';
	}
}