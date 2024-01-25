#include <bits/stdc++.h>
using namespace std;

string	text, line;

int	main()
{
	int	i = 0, count = 0;

	cin >> text >> line;
	for (auto c : line)
	{
		i = i % text.size();
		if (c == text[i])
			i++;
		if (i == text.size())
			count++;
	}
	cout << count;
}