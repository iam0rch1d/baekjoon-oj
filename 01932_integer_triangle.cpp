#include <iostream>
#include <vector>

using namespace std;

int memoize(vector<vector<int>> &a, vector<vector<int>> &dp, int y, int x) {
    if (y == a.size() - 1) return a[y][x];

    int &ret = dp[y][x];

    if (ret != -1) return ret;

    return ret = a[y][x] + max(memoize(a, dp, y + 1, x), memoize(a, dp, y + 1, x + 1));
}

int main() {
    int n;

    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    cout << memoize(a, dp, 0, 0) << '\n';

    return 0;
}
