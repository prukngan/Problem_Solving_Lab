#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<int>	cache;
	list<int>			pages;
	int	num_pages, num_requests, request, miss = 0;
	int	front, last;

	cin >> num_pages >> num_requests;
	for (int i = 0; i < num_requests; i++)
	{
		cin >> request;
		if (cache.find(request) == cache.end())
		{
			miss++;
			if (cache.size() == num_pages)
			{
				cache.erase(pages.front());
				pages.pop_front();
			}
			cache.insert(request);
			pages.push_back(request);
		}
	}
	cout << miss;
	return (0);
}