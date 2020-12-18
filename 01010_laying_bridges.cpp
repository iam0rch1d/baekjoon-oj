#include <cstring>
#include <iostream>

using namespace std;

long long dp[31][31];

long long memoize(int n, int m) {
    if (n == 0 || n == m) return 1;

    long long &ret = dp[n][m];

    if (ret != -1) return ret;

    return ret = memoize(n - 1, m - 1) + memoize(n, m - 1);
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int m;

        cin >> n >> m;

        memset(dp, -1, sizeof(dp));

        cout << memoize(n, m) << '\n';
    }

    return 0;
}
