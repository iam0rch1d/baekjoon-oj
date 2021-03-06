#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 987654321

int main() {
    int n;

    cin >> n;

    vector<int> a(n);
    vector<int> dp(n, INF);

    for (int &ai : a) {
        cin >> ai;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            if (i + j >= n) break;

            chmin(dp[i + j], dp[i] + 1);
        }
    }

    cout << (dp[n - 1] == INF ? -1 : dp[n - 1]) << '\n';

    return 0;
}
