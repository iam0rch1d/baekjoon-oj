#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void chmax(T &m, T q) { m = max(m, q); }

int t[1500000];
long long p[1500000];
long long dp[1500051];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        chmax(dp[i + t[i]], dp[i] + p[i]);
        chmax(dp[i + 1], dp[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}
