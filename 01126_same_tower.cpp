#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

#define MAX_DIFFERENCE 250000
#define NEGINF -987654321

int a[50];
int dp[50][250001];  // (<piece>, <difference>)

int main() {
    int n;

    cin >> n;

    REP(i, n) cin >> a[i];

    FUN<int(int, int)> memoize = [&](int piece, int difference) {
        if (difference > MAX_DIFFERENCE) return NEGINF;

        if (piece == n) return !difference ? 0 : NEGINF;

        int &ret = dp[piece][difference];

        if (ret != -1) return ret;

        return ret = max({memoize(piece + 1, difference),
                          memoize(piece + 1, difference + a[piece]),
                          memoize(piece + 1, abs(difference - a[piece])) + min(difference, a[piece])});
    };

    RESET(dp, -1);

    int ans = memoize(0, 0);

    PRINTLN(ans > 0 ? ans : -1);

    return 0;
}
