#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1
#define MODULO 1000000009

long long dp[1000001];

long long memoize(int target) {
    if (n <= 2) return n;
    else if (n == 3) return 4;

    long long &methodCount = dp[n];

    if (methodCount != UNKNOWN) return methodCount;

    return methodCount = (memoize(n - 1)
                          + memoize(n - 2)
                          + memoize(n - 3)) % MODULO;
}

int main() {
    int t;

    memset(dp, UNKNOWN, sizeof(dp));

    cin >> t;

    while (t--) {
        int target;

        cin >> target;

        cout << memoize(target) << '\n';
    }

    return 0;
}
