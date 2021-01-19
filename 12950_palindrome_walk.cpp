#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 987654321

char adjacent[20][20];
int dp[20][20];

int main() {
    int n;
    int m;

    cin >> n >> m;

    REP(i, n) {
        REP(j, n) {
            adjacent[i][j] = '.';
            dp[i][j] = i == j ? 0 : INF;
        }
    }

    while (m--) {
        int a;
        int b;
        char c;

        cin >> a >> b >> c;

        adjacent[a][b] = c;
        adjacent[b][a] = c;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    // pi -> i -> .. -> j -> nj
    FOR_(dist, 2, 400) {
        REP(i, n) {
            REP(j, n) {
                if (dp[i][j] != INF) {
                    REP(pi, n) {
                        REP(nj, n) {
                            if (adjacent[pi][i] != '.' && adjacent[pi][i] == adjacent[j][nj]) {
                                chmin(dp[pi][nj], dp[i][j] + 2);
                            }
                        }
                    }
                }
            }
        }
    }

    PRINTLN(dp[0][1] >= INF ? -1 : dp[0][1]);

    return 0;
}
