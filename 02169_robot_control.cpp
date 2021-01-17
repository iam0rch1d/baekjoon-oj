#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR_(i, x, y) for (int i = (y); i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define NEGINF -987654321

int a[1002][1002];
int dp[1002][1002][3];

int main() {
    int n;
    int m;

    cin >> n >> m;

    FOR_(i, 1, n) FOR_(j, 1, m) cin >> a[i][j];

    fill(&dp[0][0][0], &dp[1001][1001][2] + 1, NEGINF);

    dp[1][1][1] = a[1][1];

    FOR_(j, 2, m) dp[1][j][1] = dp[1][j - 1][1] + a[1][j];

    FOR_(i, 2, n) {
        FOR_(j, 1, m) {
            dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]}) + a[i][j];
            dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + a[i][j];
        }

        IFOR_(j, 1, m) dp[i][j][2] = max(dp[i][j + 1][0], dp[i][j + 1][2]) + a[i][j];
    }

    PRINTLN(max(dp[n][m][0], dp[n][m][1]));

    return 0;
}
