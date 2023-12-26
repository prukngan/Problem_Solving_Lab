#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m;

    set<int> values;
    for (int i = 0; i < n; i++)
	{
        cin >> x;
        values.insert(x);
    }
	for (int j = 0; j < m; j++)
	{
		cin >> y;
		auto lower = values.lower_bound(y);
		// auto upper = values.upper_bound(y);
		if (lower == values.end())
			cout << *(--lower);
		else if (*lower == y && lower == values.begin())
			cout << *lower;
		else
		{
			int	diff1 = abs(*prev(lower) - y);
			int	diff2 = abs(y - *lower);
			if (diff1 <= diff2) cout << *prev(lower);
			else cout << *lower;
		}
		cout << endl;
	}
    return (0);
}
