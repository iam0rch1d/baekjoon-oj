#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> dp(10001, 1);
    int t;

    for (int j = 2; j <= 3; j++) {
        for (int i = 1; i <= 10000; i++) {
            if (i - j >= 0) dp[i] += dp[i - j];
        }
    }

    cin >> t;

    while (t--) {
        int n;

        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
