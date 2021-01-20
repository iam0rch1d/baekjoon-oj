#include <iostream>

using namespace std;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 987654321

int a[501];
int dp[501][101];  // (<horizontal lines(y)>, <vertical lines(x)>)

int main() {
    int m;
    int n;
    int from;
    int to;
    int x;
    int y;

    cin >> m >> n >> from >> to >> x >> y;

    FOR_(i, 1, n) cin >> a[i];

    FOR_(i, 1, n) FOR_(j, 1, m) dp[i][j] = INF;

    FOR_(i, 1, m) dp[0][i] = abs(i - from) * y;

    FOR_(i, 1, n) {
        FOR_(j, 1, m) {
            int &currentVertex = dp[i][j];

            FOR_(pj, 1, m) {
                if (pj == j && (a[i] == pj || a[i] == pj - 1)) chmin(currentVertex, dp[i - 1][pj] + x);
                else if ((a[i] >= pj && a[i] <= j - 1) || (a[i] >= j && a[i] <= pj - 1)) {
                    chmin(currentVertex, dp[i - 1][pj] + (abs(j - pj) - 1) * y);
                } else chmin(currentVertex, dp[i - 1][pj] + abs(j - pj) * y);
            }
        }
    }

    PRINTLN(dp[n][to]);

    return 0;
}
