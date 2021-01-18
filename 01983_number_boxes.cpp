#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

#define NEGINF -987654321

int dp[400][400][400];

int main() {
    int n;

    cin >> n;

    vi a[2];

    for (vi &ai : a) {
        REP(j, n) {
            int aij;

            cin >> aij;

            if (aij) ai.push_back(aij);
        }
    }

    int upSize = a[0].size();
    int downSize = a[1].size();

    FUN<int(int, int, int)> memoize = [&](int x, int u, int d) {
        if (u == upSize && d == downSize) return 0;

        int &ret = dp[x][u][d];

        if (ret != NEGINF) return ret;

        ret = memoize(x + 1, u + 1, d + 1) + a[0][u] * a[1][d];

        if (x + upSize - u < n) chmax(ret, memoize(x + 1, u, d + 1));

        if (x + downSize - d < n) chmax(ret, memoize(x + 1, u + 1, d));

        return ret;
    };

    REP(i, n) REP(j, upSize) REP(k, downSize) dp[i][j][k] = NEGINF;

    PRINTLN(memoize(0, 0, 0));

    return 0;
}
