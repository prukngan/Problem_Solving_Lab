#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>	boat;
	int	boatNum, week, weekCount;
	int	seatNum, peopleNum;

	cin >> boatNum >> week;
	for (int i = 0; i < boatNum; i++)
	{
		cin >> seatNum;
		boat.push_back(seatNum);
	}
	sort(boat.begin(), boat.end());
	for (weekCount = 0; weekCount < week; weekCount++)
	{
		cin >> peopleNum;
		auto itr = lower_bound(boat.begin(), boat.end(), peopleNum); 
		if (itr == boat.end())
			break;
		boat.erase(itr);
	}
	cout << weekCount;
	return (0);
}