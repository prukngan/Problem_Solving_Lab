#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, l;
	int	start, end;
	int	farest;

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
	}

	cout << (end / l) + min(1, end % l) << '\n';

	return (0);
}