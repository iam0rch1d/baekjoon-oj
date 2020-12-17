#include <algorithm>
#include <iostream>

using namespace std;

int n;
int a[1000];
int dp[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        dp[i] = a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }

    cout << *max_element(dp, dp + n) << '\n';

    return 0;
}
