#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1
#define MODULO 1000000009

long long dp[100001][4];

long long memoize(int target, int firstNumber) {
    // 1 -> {1, 2}, 2 -> {2, 1}, 3 -> {3}
    if (target == 1) return firstNumber == 1 ? 1 : 0;
    else if (target == 2) return firstNumber == 2 ? 1 : 0;
    else if (target == 3) return 1;

    long long &ret = dp[target][firstNumber];

    if (ret != UNKNOWN) return ret;

    if (firstNumber == 1) return ret = memoize(target - 1, 2) + memoize(target - 1, 3) % MODULO;
    else if (firstNumber == 2) return ret = memoize(target - 2, 1) + memoize(target - 2, 3) % MODULO;
    else if (firstNumber == 3) return ret = memoize(target - 3, 1) + memoize(target - 3, 2) % MODULO;
    else return ret = 0;
}

int main() {
    int t;

    memset(dp, UNKNOWN, sizeof(dp));

    cin >> t;

    while (t--) {
        int target;

        cin >> target;
        cout << (memoize(target, 1) + memoize(target, 2) + memoize(target, 3)) % MODULO << '\n';
    }

    return 0;
}
