#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

using ll = long long;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

ll combination[11][11];
ll dp[11][101][101][101];

int main() {
    int n;
    int r;
    int g;
    int b;

    cin >> n >> r >> g >> b;

    combination[0][0] = 1;

    FOR_(i, 1, n) {
        combination[i][0] = 1;
        combination[i][n] = 1;

        FOR(j, 1, n) combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
    }

    FUN<ll(int, int, int, int)> memoize = [&](int n, int r, int g, int b) -> ll {
        if (r < 0 || g < 0 || b < 0) return 0;

        if (!n) return 1;

        ll &ret = dp[n][r][g][b];

        if (ret != -1) return ret;

        ret = memoize(n - 1, r - n, g, b) + memoize(n - 1, r, g - n, b) + memoize(n - 1, r, g, b - n);

        if (n % 2 == 0) {
            ret += memoize(n - 1, r - n / 2, g - n / 2, b) * combination[n][n / 2];
            ret += memoize(n - 1, r, g - n / 2, b - n / 2) * combination[n][n / 2];
            ret += memoize(n - 1, r - n / 2, g, b - n / 2) * combination[n][n / 2];
        }

        if (n % 3 == 0) {
            ret += memoize(n - 1, r - n / 3, g - n / 3, b - n / 3)
                   * combination[n][n / 3] * combination[n - n / 3][n / 3];
        }

        return ret;
    };

    RESET(dp, -1);
    PRINTLN(memoize(n, r, g, b));

    return 0;
}
