#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR_(i, x, y) for (int i = (y); i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int a[16];
bool dp[81][81][81][81];

int main() {
    int n;

    cin >> n;

    REP(i, n) cin >> a[i];

    dp[0][0][0][0] = true;

    REP(i, n) {
        IFOR_(u, 0, 80) {
            IFOR_(d, 0, 80) {
                IFOR_(l, 0, 80) {
                    IFOR_(r, 0, 80) {
                        if (!dp[u][d][l][r]) continue;

                        if (u + a[i] <= 80) dp[u + a[i]][d][l][r] = true;

                        if (d + a[i] <= 80) dp[u][d + a[i]][l][r] = true;

                        if (l + a[i] <= 80) dp[u][d][l + a[i]][r] = true;

                        if (r + a[i] <= 80) dp[u][d][l][r + a[i]] = true;
                    }
                }
            }
        }
    }

    int ans = -1;

    FOR_(i, 1, 80) FOR_(j, 1, 80) if (dp[i][i][j][j]) chmax(ans, i * j);

    PRINTLN(ans);

    return 0;
}
