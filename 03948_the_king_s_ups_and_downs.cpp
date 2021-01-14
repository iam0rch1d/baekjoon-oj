#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

using ll = long long;

#define FUN function
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'
#define RESET(arr, x) memset(arr, x, sizeof(arr))

ll combinations[21][21];
ll dp[21];

int main() {
    combinations[0][0] = 1;

    FOR_(i, 1, 20) {
        combinations[i][0] = 1;
        combinations[i][i] = 1;

        FOR_(j, 1, i - 1) combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j];
    }

    RESET(dp, -1);

    FOR_(i, 0, 2) dp[i] = 1;

    FUN<ll(int)> memoize = [&](int n) {
        ll ret = dp[n];

        if (ret != -1) return ret;

        ret = 0;

        for (int i = 1; i <= n; i += 2) {
            ret += memoize(i - 1) * memoize(n - i) * combinations[n - 1][i - 1];
        }

        return ret;
    };

    int tc;

    cin >> tc;

    while (tc--) {
        int n;

        cin >> n;

        ll ans = 1;

        if (n >= 2) ans = memoize(n) * 2;

        PRINTLN(ans);
    }

    return 0;
}
