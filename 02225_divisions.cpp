#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 1000000000

long long dp[201];

int main() {
    int n;
    int k;

    cin >> n >> k;

    dp[0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - 1]) % MODULO;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
