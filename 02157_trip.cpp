#include <cstring>
#include <iostream>

using namespace std;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int adjacent[301][301];
int dp[301][301];  // (<city>, <visits>)

int main() {
    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    while (k--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        chmax(adjacent[a][b], c);
    }

    RESET(dp, -1);

    dp[1][1] = 0;

    FOR_(visits, 1, m - 1) {
        FOR_(city, 1, n) {
            if (dp[city][visits] == -1) continue;

            FOR_(nextCity, city + 1, n) {
                if (adjacent[city][nextCity]) {
                    chmax(dp[nextCity][visits + 1], dp[city][visits] + adjacent[city][nextCity]);
                }
            }
        }
    }

    int ans = -1;

    FOR_(i, 2, m) chmax(ans, dp[n][i]);

    PRINTLN(ans);

    return 0;
}
