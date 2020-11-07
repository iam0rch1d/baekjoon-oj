#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    priority_queue<int> profits;
    int productIndex = 0;
    int totalProfit = 0;

    cin >> n;

    vector<pair<int, int>> products(n);  // .first = <profit>, .second = <deadline>

    for (auto &product : products) {
        cin >> product.first >> product.second;
    }

    sort(products.begin(), products.end(), [](auto i, auto j) { return i.second > j.second; });

    for (int i = 10000; i >= 1; i--) {
        while (productIndex < n && products[productIndex].second == i) {
            profits.push(products[productIndex++].first);
        }

        if (!profits.empty()) {
            totalProfit += profits.top();

            profits.pop();
        }
    }

    cout << totalProfit << '\n';

    return 0;
}
