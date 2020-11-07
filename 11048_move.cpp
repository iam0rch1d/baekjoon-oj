#include <iostream>
#include <vector>

using namespace std;

int maxTotalCandyCache[1000][1000];

int main() {
    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> candies(n, vector<int>(m));

    for (auto &candiesRow : candies) {
        for (int &candy : candiesRow) {
            cin >> candy;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int maxPreviousTotalCandies = 0;

            for (int k = 0; k < 3; k++) {
                int pi = i - ("101"[k] - '0');
                int pj = j - ("011"[k] - '0');

                if (pi < 0 || pj < 0) continue;

                maxPreviousTotalCandies = max(maxPreviousTotalCandies, maxTotalCandyCache[pi][pj]);
            }

            maxTotalCandyCache[i][j] = candies[i][j] + maxPreviousTotalCandies;
        }
    }

    cout << maxTotalCandyCache[n - 1][m - 1] << '\n';

    return 0;
}
