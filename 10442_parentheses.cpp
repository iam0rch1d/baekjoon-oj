#include <iostream>

using namespace std;

#define MODULO 1000000007

long long dp[5001];

int main() {
    int tc;

    dp[0] = 1;

    for (int i = 2; i <= 5000; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            dp[i] = (dp[i] + dp[j - 2] * dp[i - j] % MODULO) % MODULO;
        }
    }

    cin >> tc;

    while (tc--) {
        int l;

        cin >> l;
        cout << dp[l] << '\n';
    }

    return 0;
}
