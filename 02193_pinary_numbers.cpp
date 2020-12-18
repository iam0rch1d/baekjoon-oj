#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 1000000000

long long dp[91][2];

long long memoize(int size, int startNumber) {
    if (size == 1) return 1;

    long long &ret = dp[size][startNumber];

    if (ret != -1) return ret;

    return ret = memoize(size - 1, 0) + (startNumber == 0 ? memoize(size - 1, 1) : 0);
}

int main() {
    int n;

    memset(dp, -1, sizeof(dp));

    cin >> n;
    cout << memoize(n, 1) << '\n';

    return 0;
}
