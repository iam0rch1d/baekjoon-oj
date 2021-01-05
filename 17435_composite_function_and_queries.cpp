#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define MAX_POWER 20

int dp[200001][MAX_POWER];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;

    cin >> m;

    FOR_(i, 1, m) cin >> dp[i][0];

    FOR(j, 1, MAX_POWER) FOR_(i, 1, m) if (dp[i][j - 1]) dp[i][j] = dp[dp[i][j - 1]][j - 1];

    int q;

    cin >> q;

    while (q--) {
        int n;
        int x;

        cin >> n >> x;

        FOR(i, 0, MAX_POWER) if (n & (1 << i)) x = dp[x][i];

        PRINTLN(x);
    }

    return 0;
}
