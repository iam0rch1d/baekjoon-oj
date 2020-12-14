#include <iostream>
#include <vector>

using namespace std;

int maxTotalCandyCache[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> candies(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> candies[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            maxTotalCandyCache[i][j] = max(maxTotalCandyCache[i - 1][j], maxTotalCandyCache[i][j - 1]) + candies[i][j];
        }
    }

    cout << maxTotalCandyCache[n][m] << '\n';

    return 0;
}
