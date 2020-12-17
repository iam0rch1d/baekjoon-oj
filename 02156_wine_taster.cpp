#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> wines(n);
    vector<int> dp(n);

    for (int &wine : wines) {
        cin >> wine;
    }

    dp[0] = wines[0];

    if (wines.size() == 1) {
        cout << dp[0] << '\n';

        return 0;
    }

    dp[1] = wines[1] + wines[0];

    if (wines.size() == 2) {
        cout << dp[1] << '\n';

        return 0;
    }

    dp[2] = max({wines[0] + wines[1], wines[0] + wines[2], wines[1] + wines[2]});

    if (wines.size() == 3) {
        cout << dp[2] << '\n';

        return 0;
    }

    for (int i = 3; i < n; i++) {
        dp[i] = max({wines[i] + wines[i - 1] + dp[i - 3], wines[i] + dp[i - 2], dp[i - 1]});
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
