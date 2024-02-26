#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	n, d, r; // num of bus, mininum hour must not pay, pay r taka/hour

	while (cin >> n >> d >> r, n || d || r)
	{
		vector<int>	morning(n);
		for (int i = 0; i < n; i++)
			cin >> morning[i];
		sort(morning.begin(), morning.end());

		vector<int>	evening(n);
		for (int i = 0; i < n; i++)
			cin >> evening[i];
		sort(evening.begin(), evening.end());
		
		int	pay = 0;
		for (int i = 0; i < n; i++) {
			pay += max(0, (morning[i] + evening[n - i - 1]) - d) * r;
		}
		cout << pay << '\n';
	}
}