#include <bits/stdc++.h>
using namespace std;

int main()
{
	int	n, k, val, cost;

	cin >> n >> k;
	vector<int>	books;
	cin >> val;
	books.push_back(val);
	for (int i = 1; i < n; i++)
	{
		cin >> val;
		books.push_back(val + books[i-1]);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> cost;
		cout << upper_bound(books.begin(), books.end(), cost) - books.begin() << endl;
	}
	return (0);
}