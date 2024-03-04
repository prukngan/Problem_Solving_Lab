#include <bits/stdc++.h>
using namespace std;

struct task {
    int d;  // Deadline
    int t;  // Time
};

bool sortByDeadline(const task& a, const task& b) {
    return (a.d < b.d); // Sort tasks by deadline
}

int main() {

	int	n;

	cin >> n;
    vector<task> tasks(n);
	for (auto &task : tasks)
		cin >> task.d >> task.t;
	
    sort(tasks.begin(), tasks.end(), sortByDeadline);

	int	curr_time = 0, pay = 0;
	for (auto &task : tasks) {
		curr_time += task.t;
		pay = max(pay, (curr_time - task.d - 10) * 1000);
	}

	cout << pay << '\n';
    return (0);
}
