#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	numCase;
	int	n, h, ta, tb;

	cin >> numCase;
	for (int i = 1; i <= numCase; i++)
	{
		cin >> n >> h >> ta >> tb;

		vector<int>	h_hippo(n);
		for (int hippo = 0; hippo < n; hippo++)
			cin >> h_hippo[hippo];

		sort(h_hippo.begin(), h_hippo.end());
		cout << "Case " << i << ": ";
		if (tb >= ta * 2)
			cout << ta * n;
		else
		{
			int	time = 0;
			int	start = 0, end = n - 1;
			while (start < end)
			{
				if (h_hippo[start] + h_hippo[end] < h) {
					start++; end--;
					time += tb;
				}
				else {
					end--;
					time += ta;
				}
			}
			if (start == end)
				time += ta;
			cout << time;
		}
		cout << '\n';
	}
}