#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define F first
#define S second
#define PRINTLN(x) cout << (x) << '\n'

typedef pair<pll, pll> Line;

int ccw(pll u, pll v, pll w) {
    ll temp = u.F * v.S + v.F * w.S + w.F * u.S - u.S * v.F - v.S * w.F - w.S * u.F;

    return temp > 0 ? 1 : temp < 0 ? -1 : 0;
}

bool isCrossing(Line l1, Line l2) {
    if (l1.F > l1.S) swap(l1.F, l1.S);
    if (l2.F > l2.S) swap(l2.F, l2.S);

    int ccwL1L2 = ccw(l1.F, l1.S, l2.F) * ccw(l1.F, l1.S, l2.S);
    int ccwL2L1 = ccw(l2.F, l2.S, l1.F) * ccw(l2.F, l2.S, l1.S);

    if (!ccwL1L2 && !ccwL2L1) return l1.S >= l2.F && l2.S >= l1.F;
    else return ccwL1L2 <= 0 && ccwL2L1 <= 0;
}

int main() {
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    PRINTLN(isCrossing({{x1, y1}, {x2, y2}}, {{x3, y3}, {x4, y4}}));

    return 0;
}
