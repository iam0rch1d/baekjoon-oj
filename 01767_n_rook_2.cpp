#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 1000001

template<typename T>
void chmodadd(T &x, T q) {
    x = (x + q) % MODULO;
}

template<typename T>
T modmul(T x, T y) {
    return x * y % MODULO;
}

long long dp[101][101][101];

long long memoize(long long n, long long m, long long k) {
    if (!k) return 1;
    else if (n <= 0 || m <= 0 || k < 0) return 0;

    auto &ret = dp[n][m][k];

    if (ret != -1) return ret;

    ret = 0;

    chmodadd(ret, memoize(n - 1, m, k));
    chmodadd(ret, modmul(memoize(n - 1, m - 1, k - 1), m));
    chmodadd(ret, modmul(memoize(n - 1, m - 2, k - 2), m * (m - 1) / 2));
    chmodadd(ret, modmul(memoize(n - 2, m - 1, k - 2), m * (n - 1)));

    return ret;
}

int main() {
    long long n;
    long long m;
    long long k;

    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> k;
    cout << memoize(n, m, k) << '\n';

    return 0;
}
