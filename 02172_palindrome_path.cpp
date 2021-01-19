#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int a[20][20];
int dp[21][20][20][20][20];
int dy[]{-1, -1, -1, 0, 0, 1, 1, 1};
int dx[]{-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    int l;

    cin >> n >> l;

    REP(i, n) REP(j, n) cin >> a[i][j];

    FUN<int(int, int, int, int, int)> memoize = [&](int l, int sy, int sx, int ey, int ex) -> int {
        if (l == 1) return sy == ey && sx == ex;
        else if (l == 2) {
            REP(i, 8) if (sy + dy[i] == ey && sx + dx[i] == ex) return 1;

            return 0;
        }

        int &ret = dp[l][sy][sx][ey][ex];

        if (ret != -1) return ret;

        ret = 0;

        REP(i, 8) {
            REP(j, 8) {
                int nsy = sy + dy[i];
                int nsx = sx + dx[i];
                int pey = ey - dy[j];
                int pex = ex - dx[j];

                if (nsy < 0 || nsy >= n || nsx < 0 || nsx >= n || pey < 0 || pey >= n || pex < 0 || pex >= n) continue;

                if (a[nsy][nsx] == a[pey][pex]) ret += memoize(l - 2, nsy, nsx, pey, pex);
            }
        }

        return ret;
    };

    int ans = 0;

    RESET(dp, -1);

    REP(i, n * n) {
        int iy = i / n;
        int ix = i % n;

        REP(j, n * n) {
            int jy = j / n;
            int jx = j % n;

            if (a[iy][ix] == a[jy][jx]) ans += memoize(l, iy, ix, jy, jx);
        }
    }

    PRINTLN(ans);

    return 0;
}
