#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vl a(n + 1, 0);
    vl s(n + 1, 0);
    vl counts(m, 0);
    ll ans = 0;

    counts[0] = 1;

    FOR_(i, 1, n) {
        cin >> a[i];

        s[i] = (s[i - 1] + a[i]) % m;
        counts[s[i]]++;
    }

    REP(i, m) ans += counts[i] * (counts[i] - 1) / 2;

    PRINTLN(ans);

    return 0;
}
