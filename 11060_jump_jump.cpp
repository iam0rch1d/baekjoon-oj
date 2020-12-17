#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

template<typename T>
void chmin(T &m, T q) {
    m = min(m, q);
}

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
