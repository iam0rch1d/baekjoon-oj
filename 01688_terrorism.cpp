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

typedef pair<pll, pll> Line;

int ccw(pll u, pll v, pll w) {
    ll temp = u.F * v.S + v.F * w.S + w.F * u.S - u.S * v.F - v.S * w.F - w.S * u.F;

    return temp > 0 ? 1 : temp < 0 ? -1 : 0;
}

bool isCrossing(Line l1, Line l2) {
    int ccwL1L2 = ccw(l1.F, l1.S, l2.F) * ccw(l1.F, l1.S, l2.S);
    int ccwL2L1 = ccw(l2.F, l2.S, l1.F) * ccw(l2.F, l2.S, l1.S);

    return ccwL1L2 < 0 && ccwL2L1 < 0;
}

bool isOnLine(pll p, Line l) {
    if (l.F > l.S) swap(l.S, l.F);

    return !ccw(l.F, p, l.S) && p >= l.F && p <= l.S;
}

int main() {
    int n;

    cin >> n;

    vpll barrier(n);

    for (auto &point : barrier) {
        cin >> point.F >> point.S;
    }

    REP(i, 3) {
        ll x;
        ll y;

        cin >> x >> y;

        bool isOnBorder = false;
        int crossCount = 0;

        REP(j, n) {
            Line l = {barrier[j], barrier[(j + 1) % n]};

            if (isOnLine({x, y}, l)) {
                isOnBorder = true;

                break;
            }

            crossCount += isCrossing({{x, y}, {1, 0x7fffffff}}, l);
        }

        PRINTLN(isOnBorder || crossCount % 2);
    }

    return 0;
}
