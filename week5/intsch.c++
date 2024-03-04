#include <bits/stdc++.h>
using namespace std;

struct range
{
	int	start;
	int	end;
};

bool	compare(range &a, range &b) {
	return (a.start < b.start);
}

int	main()
{
	int	n;

	cin >> n;
	vector<range>	ranges(n);
	for (auto &range : ranges) {
		cin >> range.start >> range.end;
	}

	sort(ranges.begin(), ranges.end(), compare);

	int	count = 1;
	int	preEnd = ranges[0].end;
	for (int i = 1; i < n; i++)
	{
		if (ranges[i].start < preEnd) {
			preEnd = min(preEnd, ranges[i].end);
		}
		else {
			count++;
			preEnd = ranges[i].end;
		}
	}

	cout << count << '\n';
	return (0);
}
