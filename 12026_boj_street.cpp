#include <iostream>

using namespace std;

template<typename T>
void chmin(T &m, T q) { m = min(m, q); }

#define INF 987654321

int dp[1000];

char previousOf(char c) {
    if (c == 'B') return 'J';
    else if (c == 'O') return 'B';
    else return 'O';
}

int main() {
    int n;
    string s;

    cin >> n >> s;

    for (int i = 1; i < n; i++) {
        dp[i] = INF;

        for (int j = 0; j < i; j++) {
            if (s[j] == previousOf(s[i])) chmin(dp[i], dp[j] + (i - j) * (i - j));
        }
    }

    cout << (dp[n - 1] == INF ? -1 : dp[n - 1]) << '\n';

    return 0;
}
