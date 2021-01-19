#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FUN function
#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int dp[2000][2000];

int main() {
    int n;

    cin >> n;

    vi a(n);

    REP(i, n) cin >> a[i];

    sort(ALL(a));

    int ans = 1;
    int temp = 1;

    FOR(i, 1, n) {
        if (a[i] == a[i - 1]) chmax(ans, ++temp);
        else temp = 1;
    }

    a.erase(unique(ALL(a)), a.end());

    int aUniqueSize = a.size();
    FUN<int(int, int)> memoize = [&](int index0, int index1) {
        int &ret = dp[index0][index1];

        if (ret) return ret;

        int d = a[index1] - a[index0];
        int a2 = a[index1] + d;
        int a2LowerBound = lower_bound(ALL(a), a2) - a.begin();

        return ret = a[a2LowerBound] == a2 ? memoize(index1, a2LowerBound) + 1 : 2;
    };

    REP(i, aUniqueSize - 1) FOR(j, i + 1, aUniqueSize) chmax(ans, memoize(i, j));

    PRINTLN(ans);

    return 0;
}
