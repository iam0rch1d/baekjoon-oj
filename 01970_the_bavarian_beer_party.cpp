#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int brands[1000];
int dp[1000][1000];

int memoize(int left, int right) {
    if (left >= right) return 0;

    int &ret = dp[left][right];

    if (ret != -1) return ret;

    ret = memoize(left + 1, right);

    for (int toastWith = left + 1; toastWith <= right; toastWith++) {
        if (brands[toastWith] == brands[left]) {
            chmax(ret, memoize(left + 1, toastWith - 1) + memoize(toastWith + 1, right) + 1);
        }
    }

    return ret;
}

int main() {
    int n;

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> brands[i];
    }

    cout << memoize(0, n - 1) << '\n';

    return 0;
}
