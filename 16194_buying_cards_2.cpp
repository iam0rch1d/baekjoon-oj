#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int a[1001];
int dp[1001];

int memoize(int leftCards) {
    if (leftCards == 0) return 0;

    int &ret = dp[leftCards];

    if (ret != UNKNOWN) return ret;

    ret = 100000001;

    for (int i = leftCards; i > 0; i--) {
        ret = min(ret, a[i] + memoize(leftCards - i));
    }

    return ret;
}

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, UNKNOWN, sizeof(dp));

    cout << memoize(n) << '\n';

    return 0;
}
