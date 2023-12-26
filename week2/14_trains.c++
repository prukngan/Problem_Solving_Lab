#include <bits/stdc++.h>
using namespace std;

int	main()
{
	long		n, a, b;
	char		symbol;
	list<long>	platform[100100];
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> symbol >> a >> b;
		if (symbol == 'N')
			platform[b].push_back(a);
		else if (symbol == 'M')
			platform[b].splice(platform[b].end(), platform[a]);
		// cout << "-------------------------------------";
		// for (int i = 0; i < n; i++)

		// {
		// 	for (auto &val : platform[i])
		// 		cout << val << ' ';
		// 	cout << endl;
		// }
	}
	// cout << "-------------------------------------" << endl;
	for (int i = 0; i < 100001; i++)
	{
		for (auto &val : platform[i])
			cout << val << endl;
	}
	return (0);
}