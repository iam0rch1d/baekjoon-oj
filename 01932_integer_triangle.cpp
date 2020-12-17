#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

#define UNKNOWN -1

int memoize(vector<vector<int>> &a, vector<vector<int>> &dp, Point from) {
    if (from.y == a.size() - 1) return a[from.y][from.x];

    int &ret = dp[from.y][from.x];

    if (ret != UNKNOWN) return ret;

    return ret = a[from.y][from.x]
                 + max(memoize(a, dp, {from.y + 1, from.x}), memoize(a, dp, {from.y + 1, from.x + 1}));
}

int main() {
    int n;

    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, UNKNOWN));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    cout << memoize(a, dp, {0, 0}) << '\n';

    return 0;
}
