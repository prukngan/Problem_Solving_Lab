#include <bits/stdc++.h>
using namespace std;

int	main()
{
	list<int>	dataSet;
	int	dataLen, orderNum;
	int	data, order;

	cin >> dataLen >> orderNum;
	for (int i = 0; i < dataLen; i++)
	{
		cin >> data;
		dataSet.push_back(data);
	}
	list<int>::iterator	itr = dataSet.begin();
	for (int i = 0; i < orderNum; i++)
	{
		cin >> order;
		if (order == 1)
			itr = dataSet.begin();
		else if (order == 2)
		{
			if (*itr == dataSet.back())
				itr = dataSet.begin();
			else
				itr++;
		}
		else if (order == 3)
		{
			cin >> data;
			dataSet.insert(itr, data);
		}
		else if (order == 4)
		{
			cin >> data;
			dataSet.insert(++itr, data);
			itr--; itr--;
		}
	}
	for (auto &it : dataSet)
		cout << it << ' ';
	cout << '\n';
	return (0);
}