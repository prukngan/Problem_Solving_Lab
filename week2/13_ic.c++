#include <bits/stdc++.h>
using namespace std;

void	connect_ic(list<int> &ic, string symbol, int num)
{
	if (symbol == "li")
		ic.push_front(num);
	else if (symbol == "ri")
		ic.push_back(num);
	else if (symbol == "lr" && ic.size() > 1)
	{
		num = ic.front(); ic.pop_front();
		ic.push_back(num);
	}
	else if (symbol == "rr" && ic.size() > 1)
	{
		num = ic.back(); ic.pop_back();
		ic.push_front(num);
	}
}

int	main()
{
	list<int>	ic;
	string		symbol;
	int			n, num;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> symbol;
		if (symbol == "li" || symbol == "ri")
			cin >> num;
		connect_ic(ic, symbol, num);
	}
	for (auto &val : ic)
		cout << val << '\n';
	return (0);
}