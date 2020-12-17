#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int dp[11];

int memoize(int n) {
    if (n <= 2) return n;
    else if (n == 3) return 4;

    int &ret = dp[n];

    if (ret != UNKNOWN) return ret;

    return ret = memoize(n - 1) + memoize(n - 2) + memoize(n - 3);
}

int main() {
    int tc;

    cin >> tc;

    memset(dp, UNKNOWN, sizeof(dp));

    while (tc--) {
        int n;

        cin >> n;
        cout << memoize(n) << '\n';
    }

    return 0;
}
