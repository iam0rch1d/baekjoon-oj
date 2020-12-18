#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[1000001];

int memoize(int x) {
    if (x == 1) return 0;

    int &ret = dp[x];

    if (ret != -1) return ret;

    int whenDividedBy3 = x % 3 == 0 ? 1 + memoize(x / 3) : 1000000;
    int whenDividedBy2 = x % 2 == 0 ? 1 + memoize(x / 2) : 1000000;

    return ret = min({1 + memoize(x - 1), whenDividedBy2, whenDividedBy3});
}

int main() {
    int x;

    memset(dp, -1, sizeof(dp));

    cin >> x;
    cout << memoize(x) << '\n';

    return 0;
}
