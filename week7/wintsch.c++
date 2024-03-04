#include <bits/stdc++.h>
using namespace std;

struct task {
    int start, end, weight;
};

bool compare(const task &a, const task &b) {
    return a.end < b.end;
}

int main()
{
	int	n;

	cin >> n;
	vector<task>	taskList(n);
	for (int i = 0; i < n; i++) {
		cin >> taskList[i].start >> taskList[i].end >> taskList[i].weight;
	}

	sort(taskList.begin(), taskList.end(), compare);

	vector<int>	dp(n);
	vector<list<int>>	result(n);
	
	dp[0] = taskList[0].weight;
	result[0].push_back(1);
	for (int i = 1; i < n; i++)
	{
        int	currWeight = taskList[i].weight;

		int	j = i - 1;
       	for (; j >= 0; j--) {
			if (taskList[j].end <= taskList[i].start) {
				currWeight += dp[j];
				break;
        	}
    	}

		if (currWeight > dp[i - 1])
		{
			dp[i] = currWeight;
			result[i].push_back(i + 1);
			if (j > -1)
				result[i].splice(result[i].begin(), result[j]);
		}
		else
			dp[i] = dp[i - 1];
    }

	cout << dp[n - 1] << '\n';

	cout << result[n - 1].size() << '\n';

	for (auto &itr : result[n - 1]) {
		cout << itr << ' ';
	}

    return 0;
}