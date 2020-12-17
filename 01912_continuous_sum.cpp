#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    int a[100000];
    int dp[100000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        dp[i] = a[i] + (i == 0 ? 0 : max(dp[i - 1], 0));
    }

    cout << *max_element(dp, dp + n) << '\n';

    return 0;
}
