#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

int r[500];
int c[500];
long long dp[500][500];

long long memoize(int left, int right) {
    if (left >= right) return 0;
    else if (right - left == 1) return r[left] * c[left] * c[right];

    long long &ret = dp[left][right];

    if (ret) return ret;

    ret = 0xffffffff;

    for (int i = left; i <= right - 1; i++) {
        chmin(ret, memoize(left, i) + memoize(i + 1, right) + r[left] * c[i] * c[right]);
    }

    return ret;
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
    }

    cout << memoize(0, n - 1) << '\n';

    return 0;
}
