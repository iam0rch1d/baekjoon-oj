#include <iostream>

using namespace std;

long long dp[101];

template<typename T>
void chmax(T &m, T q) {
    m = max(m, q);
}

int main() {
    int n;

    cin >> n;

    if (n <= 6) {
        cout << n << '\n';

        return 0;
    }

    for (int i = 1; i <= 6; i++) {
        dp[i] = i;
    }

    for (long long i = 7; i <= n; i++) {
        for (long long j = 1; j <= 3; j++) {
            chmax(dp[i], dp[i - j - 2] * (j + 1));
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
