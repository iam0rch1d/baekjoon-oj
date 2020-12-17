#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int dp[100001];

int memoize(int n) {
    if (n == 0) return 0;

    int &ret = dp[n];

    if (ret != UNKNOWN) return ret;

    ret = n;

    for (int i = 1; i * i <= n; i++) {
        ret = min(ret, memoize(n - i * i) + 1);
    }

    return ret;
}

int main() {
    int n;

    memset(dp, UNKNOWN, sizeof(dp));

    cin >> n;
    cout << memoize(n) << '\n';

    return 0;
}
