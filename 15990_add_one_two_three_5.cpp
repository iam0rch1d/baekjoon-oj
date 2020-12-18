#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 1000000009

long long dp[100001][4];

long long memoize(int n, int firstNumber) {
    // 1 -> {1, 2}, 2 -> {2, 1}, 3 -> {3}
    if (n == 1) return firstNumber == 1 ? 1 : 0;
    else if (n == 2) return firstNumber == 2 ? 1 : 0;
    else if (n == 3) return 1;

    long long &ret = dp[n][firstNumber];

    if (ret != -1) return ret;

    if (firstNumber == 1) return ret = memoize(n - 1, 2) + memoize(n - 1, 3) % MODULO;
    else if (firstNumber == 2) return ret = memoize(n - 2, 1) + memoize(n - 2, 3) % MODULO;
    else if (firstNumber == 3) return ret = memoize(n - 3, 1) + memoize(n - 3, 2) % MODULO;
    else return ret = 0;
}

int main() {
    int tc;

    memset(dp, -1, sizeof(dp));

    cin >> tc;

    while (tc--) {
        int n;

        cin >> n;
        cout << (memoize(n, 1) + memoize(n, 2) + memoize(n, 3)) % MODULO << '\n';
    }

    return 0;
}
