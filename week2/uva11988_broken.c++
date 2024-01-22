#include <bits/stdc++.h>
using namespace std;

int	main()
{
	string	line;

	while (cin >> line, !cin.eof())
	{
		list<char>				text;
		list<char>::iterator	itr = text.begin();

		for (int i = 0; line[i] != '\0'; i++)
		{
			if (line[i] == '[')
				itr = text.begin();
			else if (line[i] == ']')
				itr = text.end();
			else
				text.insert(itr, line[i]);
		}
		for (auto &itr : text)
			cout << itr;
		cout << endl;
	}
}