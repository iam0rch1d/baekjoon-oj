#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
void chmax(T &m, T q) { m = max(m, q); }

int smallSize;
int a[50001];
int s[50001];
int dp[50001][4];

int memoize(int large, int small) {
    if (!small) return 0;

    int &ret = dp[large][small];

    if (ret != -1) return ret;

    chmax(ret, memoize(large - smallSize, small - 1) + s[large] - s[large - smallSize]);

    if (large > smallSize * small) chmax(ret, memoize(large - 1, small));

    return ret;
}

int main() {
    int largeSize;

    memset(dp, -1, sizeof(dp));

    cin >> largeSize;

    for (int i = 1; i <= largeSize; i++) {
        cin >> a[i];

        s[i] = s[i - 1] + a[i];
    }

    cin >> smallSize;
    cout << memoize(largeSize, 3) << '\n';

    return 0;
}
