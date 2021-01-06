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
            int pi = i - coinValues[j];

            if (pi >= 0) dp[i] = min(dp[i], dp[pi] + 1);
        }
    }

    cout << (dp[k] == 100001 ? -1 : dp[k] - 1) << '\n';

    return 0;
}
