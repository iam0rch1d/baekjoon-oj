#include <cstring>
#include <iostream>

using namespace std;

int a[1001];
int dp[1001];

int memoize(int leftCards) {
    if (leftCards == 0) return 0;

    int &ret = dp[leftCards];

    if (ret != -1) return ret;

    ret = 0;

    for (int i = leftCards; i > 0; i--) {
        ret = max(ret, a[i] + memoize(leftCards - i));
    }

    return ret;
}

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << memoize(n) << '\n';

    return 0;
}
