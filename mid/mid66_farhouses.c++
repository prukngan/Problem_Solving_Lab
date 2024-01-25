#include <bits/stdc++.h>
using namespace std;

int	wireMax = 0;

int	main()
{
	vector<int>	houseSet;
	// set<int>::iterator	head, tail;
	int			houseNum, passHouse, pass, dis;

	cin >> houseNum >> passHouse >> pass;
	for (int i = 0; i < houseNum; i++)
	{
		cin >> dis;
		houseSet.push_back(dis);
	}
	sort(houseSet.begin(), houseSet.end());
	passHouse += pass;
	for (int i = 0; i < houseNum; i++)
	{
		wireMax = max(wireMax, houseSet[passHouse + i] - houseSet[i]);
	}
	cout << wireMax;
	return (0);
}