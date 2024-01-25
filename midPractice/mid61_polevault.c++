#include<bits/stdc++.h>
using namespace std;

int	main()
{
	int	logNum, qNum, logLen, q, sum = 0;
	set<int>	logSet;
	vector<int>	eachLog;

	cin >> logNum >> qNum;
	for (int i = 0; i < logNum; i++)
	{
		cin >> logLen;
		eachLog.push_back(logLen);
	}
	for (int i = 0; i < logNum; i++)
	{
		sum = 0;
		for (int j = i;  j < logNum; j++)
		{
			sum += eachLog[j];
			logSet.insert(sum);
		}
	}
	for (int i = 0; i < qNum; i++)
	{
		cin >> q;
		set<int>::iterator	itr = logSet.lower_bound(q);
		if (itr != logSet.end() && *itr == q)
			cout << 'Y';
		else
			cout << 'N';
	}
	cout << '\n';
	return (0);
}