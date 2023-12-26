#include <bits/stdc++.h>
using namespace std;

int	main()
{
	list<int>	ls;
	char		symbol;
	int			n, num, size = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> symbol >> num;
		if (symbol == 'I')
		{
			ls.push_front(num);
			size += 1;
		}
		else if (symbol == 'D' && num - 1 >= 0 && num - 1 < size)
		{
			auto pt = ls.begin(); advance(pt, num - 1);
			ls.erase(pt);
			size -= 1;
		}
	}
	for (const auto &val : ls)
		cout << val << '\n';
	return (0);
}