#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> dp(k + 1, 0);

    dp[0] = 1;

    while (n-- > 0) {
        int coinValue;

        cin >> coinValue;

        for (int j = coinValue; j <= k; j++) {
            dp[j] += dp[j - coinValue];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}
