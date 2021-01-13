#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int a[500][500];
int dp[500][500];

int main() {
    int n;

    cin >> n;

    REP(i, n) REP(j, n) cin >> a[i][j];

    FUN<int(int, int)> memoize = [&](int y, int x) {
        int &ret = dp[y][x];

        if (ret) return ret;

        ret = 1;

        REP(i, 4) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny >= 0 && ny < n && nx >= 0 && nx < n && a[y][x] < a[ny][nx]) chmax(ret, memoize(ny, nx) + 1);
        }

        return ret;
    };

    int ans = 0;

    REP(i, n) REP(j, n) chmax(ans, memoize(i, j));

    PRINTLN(ans);

    return 0;
}
