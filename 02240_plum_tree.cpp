#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int a[1001];
int dp[1001][1001];

int main() {
    int t;
    int w;

    cin >> t >> w;

    FOR_(i, 1, t) cin >> a[i];

    FUN<int(int, int)> memoize = [&](int time, int moves) {
        if (time > t || moves > w) return 0;

        int &ret = dp[time][moves];

        if (ret != -1) return ret;

        return ret = max(memoize(time + 1, moves), memoize(time + 1, moves + 1)) + (a[time] == moves % 2 + 1);
    };

    RESET(dp, -1);
    PRINTLN(max(memoize(1, 0), memoize(1, 1)));

    return 0;
}
