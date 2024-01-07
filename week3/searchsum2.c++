#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> prices[i];
    }

    // Sort prices in descending order
    std::sort(prices.rbegin(), prices.rend());

    for (int q = 0; q < Q; ++q) {
        int M;
        std::cin >> M;

        int maxBooks = 0;
        int remainingMoney = M;

        for (int i = 0; i < N; ++i) {
            if (remainingMoney >= prices[i]) {
                remainingMoney -= prices[i];
                ++maxBooks;
            } else {
                break; // Not enough money to buy the book
            }
        }

        std::cout << maxBooks << std::endl;
    }

    return 0;
}
