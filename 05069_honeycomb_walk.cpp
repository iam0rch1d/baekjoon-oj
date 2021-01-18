#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int dp[15][29][29];  // (<distance>, <x>, <y>)
int dx[]{-1, 0, 1, 1, 0, -1};
int dy[]{1, 1, 0, -1, -1, 0};

int main() {
    int tc;

    cin >> tc;

    dp[0][14][14] = 1;

    FOR_(dist, 1, 14) {
        REP(x, 29) {
            REP(y, 29) {
                REP(direction, 6) {
                    int px = x - dx[direction];
                    int py = y - dy[direction];

                    if (px >= 0 && px < 29 && py >= 0 && py < 29) dp[dist][x][y] += dp[dist - 1][px][py];
                }
            }
        }
    }

    while (tc--) {
        int n;

        cin >> n;
        PRINTLN(dp[n][14][14]);
    }

    return 0;
}
