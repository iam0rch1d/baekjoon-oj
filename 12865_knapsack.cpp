#include <iostream>

using namespace std;

int w[101];
int v[101];
int dp[100001];

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int main() {
    int n;
    int k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j - w[i] >= 0) chmax(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[k] << '\n';

    return 0;
}
