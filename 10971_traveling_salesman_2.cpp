#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int minTotalCost = 1e7;

    cin >> n;

    vector<vector<int>> costs(n, vector<int>(n));
    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        permutation[i] = i;
    }

    while (true) {
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            if (costs[permutation[i]][permutation[(i + 1) % n]] == 0) {
                totalCost = 1e7;

                break;
            }

            totalCost += costs[permutation[i]][permutation[(i + 1) % n]];
        }

        minTotalCost = min(minTotalCost, totalCost);

        if (!next_permutation(permutation.begin(), permutation.end())) break;
    }

    cout << minTotalCost << '\n';

    return 0;
}
