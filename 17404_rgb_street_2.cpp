#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int n;
int costs[1000][3];
int dp[1000][3];

int memoize(int from, int color, int firstColor) {
    if (from == n - 1) return color == firstColor ? 1000001 : costs[from][color];

    int &ret = dp[from][color];

    if (ret != UNKNOWN) return ret;

    return ret = costs[from][color] + min(memoize(from + 1, (color + 1) % 3, firstColor),
                                          memoize(from + 1, (color + 2) % 3, firstColor));
}

int main() {
    int ans = 1000001;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    for (int i = 0; i < 3; i++) {
        memset(dp, UNKNOWN, sizeof(dp));

        ans = min(ans, memoize(0, i, i));
    }

    cout << ans << '\n';

    return 0;
}
