#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	plate[300];
	int	num, n;

	bzero(plate, sizeof(int)*300);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		plate[n] += 1;
	}
	cout << *max_element (plate, plate + 300);
}
