#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000007

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

int a[51][51];
int dp[51][51][51][51];  // (<y>, <x>, <visits>, <lastVisit>)
int ans[51];

int main() {
    int n;
    int m;
    int c;

    cin >> n >> m >> c;

    RESET(a, -1);

    REP(i, c) {
        int y;
        int x;

        cin >> y >> x;

        a[y][x] = i;
    }

    dp[1][0][0][0] = 1;

    FOR_(y, 1, n) {
        FOR_(x, 1, m) {
            if (a[y][x] == -1) chmodadd(dp[y][x][0][0], dp[y - 1][x][0][0] + dp[y][x - 1][0][0]);

            FOR_(visits, 1, c) {
                if (a[y][x] == -1) {  // Not point
                    REP(lastPoint, c) {
                        chmodadd(dp[y][x][visits][lastPoint],
                                 dp[y - 1][x][visits][lastPoint] + dp[y][x - 1][visits][lastPoint]);
                    }
                } else {  // Point
                    int point = a[y][x];

                    if (visits == 1) {
                        chmodadd(dp[y][x][visits][point], dp[y - 1][x][0][0] + dp[y][x - 1][0][0]);
                    } else {
                        REP(lastPoint, point) {
                            chmodadd(dp[y][x][visits][point],
                                     dp[y - 1][x][visits - 1][lastPoint] + dp[y][x - 1][visits - 1][lastPoint]);
                        }
                    }
                }
            }
        }
    }

    FOR_(visits, 0, c) {
        REP(lastPoint, max(1, c)) chmodadd(ans[visits], dp[n][m][visits][lastPoint]);

        PRINT(ans[visits]);
    }

    PRINTLN("");

    return 0;
}
