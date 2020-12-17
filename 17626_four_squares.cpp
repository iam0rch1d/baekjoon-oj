#include <iostream>

using namespace std;

int dp[50001];

int main() {
    int n;

    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = 5;

        for (int j = 1; j * j <= n; j++) {
            int pi = i - j * j;

            if (pi < 0 || dp[pi] == 5) continue;

            dp[i] = min(dp[i], dp[pi] + 1);
        }
    }

    cout << dp[n] - 1 << '\n';

    return 0;
}
