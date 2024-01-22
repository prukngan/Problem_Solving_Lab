#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, mv;
	queue<int> deck;

	while (cin >> n, n) {
		for (int i = 1; i <= n; i++) {
			deck.push(i);
		}

		cout << "Discarded cards:";
		while (deck.size() > 1)
		{
			cout << ' ' << deck.front();
			deck.pop();
			mv = deck.front();
			deck.pop(); deck.push(mv);
			if (deck.size() > 1)
				cout << ',';
		}
		cout << endl;
		cout << "Remaining card: " << deck.front() << endl;
		deck.pop();
	}

	return 0;
}