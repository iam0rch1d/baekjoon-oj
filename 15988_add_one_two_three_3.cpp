#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1
#define MODULO 1000000009

long long dp[1000001];

long long memoize(int n) {
    if (n <= 2) return n;
    else if (n == 3) return 4;

    long long &methodCount = dp[n];

    if (methodCount != UNKNOWN) return methodCount;

    return methodCount = (memoize(n - 1) + memoize(n - 2) + memoize(n - 3)) % MODULO;
}

int main() {
    int tc;

    memset(dp, UNKNOWN, sizeof(dp));

    cin >> tc;

    while (tc--) {
        int n;

        cin >> n;
        cout << memoize(n) << '\n';
    }

    return 0;
}
