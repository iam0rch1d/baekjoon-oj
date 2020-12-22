#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int n;

    cin >> n;

    vpll p(n);

    for (auto &pi : p) {
        cin >> pi.F >> pi.S;
    }

    ll ans2 = 0;

    REP(i, n) ans2 += p[i].F * p[(i + 1) % n].S - p[i].S * p[(i + 1) % n].F;

    cout << abs(ans2) / 2 << '.';

    PRINTLN(ans2 % 2 ? 5 : 0);

    return 0;
}
