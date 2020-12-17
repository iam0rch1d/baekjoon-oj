#include <iostream>
#include <vector>

using namespace std;

int dp[100001];

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> coinValues(n);

    for (int &coinValue : coinValues) {
        cin >> coinValue;
    }

    for (int &dpi : dp) {
        dpi = 100001;
    }

    dp[0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            int previousTotalValue = i - coinValues[j];

            if (previousTotalValue < 0) continue;

            dp[i] = min(dp[i], dp[previousTotalValue] + 1);
        }
    }

    cout << (dp[k] == 100001 ? -1 : dp[k] - 1) << '\n';

    return 0;
}
