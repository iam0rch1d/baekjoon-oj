#include <iostream>
#include <vector>

using namespace std;

#define MODULO 1000000000

int memoize(vector<vector<int>> &dp, int size, int startNumber) {
    if (size == 1) return 1;

    if (dp[size][startNumber] != -1) {
        return dp[size][startNumber];
    }

    int &ret = dp[size][startNumber];

    if (startNumber == 0) return ret = memoize(dp, size - 1, 1);
    else if (startNumber == 9) return ret = memoize(dp, size - 1, 8);
    else return ret = (memoize(dp, size - 1, startNumber + 1) + memoize(dp, size - 1, startNumber - 1)) % MODULO;
}

int main() {
    int n;
    int ans = 0;

    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(10, -1));

    for (int i = 1; i <= 9; i++) {
        ans = (ans + memoize(dp, n, i)) % MODULO;
    }

    cout << ans << '\n';

    return 0;
}
