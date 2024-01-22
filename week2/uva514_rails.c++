#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, train[1000];
	int i, stage;

	while (cin >> n, n)
	{
		while (1)
		{
			cin >> train[0];
			if (train[0] == 0)
			{
				cout << endl;
				break;
			}
			for (i = 1; i < n; i++)
				cin >> train[i];

			int trainCoah = 0;
			stack<int>	station;
			for (int currCoach = 1; currCoach <= n; currCoach++)
			{
				station.push(currCoach);
				for (; !station.empty() && trainCoah < n && station.top() == train[trainCoah]; trainCoah++)
					station.pop();
			}
			if(station.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}