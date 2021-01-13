#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int a[500][500];
int dp[500][500];

int main() {
    int n;
    int m;

    cin >> n >> m;

    REP(i, n) REP(j, m) cin >> a[i][j];

    RESET(dp, -1);

    FUN<int(int, int)> memoize = [&](int y, int x) {
        if (y == n - 1 && x == m - 1) return 1;

        int &ret = dp[y][x];

        if (ret != -1) return ret;

        ret = 0;

        REP(i, 4) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] < a[y][x]) ret += memoize(ny, nx);
        }

        return ret;
    };

    PRINTLN(memoize(0, 0));

    return 0;
}
