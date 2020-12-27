#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
T square(T x) { return x * x; }

template<typename T>
T euclidean(pair<T, T> a, pair<T, T> b) { return square(b.F - a.F) + square(b.S - a.S); }

int ccw(pll u, pll v, pll w) {
    ll temp = u.F * v.S + v.F * w.S + w.F * u.S - u.S * v.F - v.S * w.F - w.S * u.F;

    return temp > 0 ? 1 : temp < 0 ? -1 : 0;
}

int main() {
    int n;

    cin >> n;

    vpll p(n);

    for (auto &pi : p) {
        cin >> pi.F >> pi.S;
    }

    pll origin = p[0];

    FOR(i, 1, n) {
        if (p[i].S < origin.S || (p[i].S == origin.S && p[i].F < origin.F)) origin = p[i];
    }

    auto graham = [origin](pll i, pll j) {
        int temp = ccw(origin, i, j);

        if (temp == 0) return euclidean(origin, i) <= euclidean(origin, j);
        else return temp == 1;
    };

    sort(ALL(p), graham);

    vpll hull;

    REP(i, n) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[i]) <= 0) {
            hull.pop_back();
        }

        hull.push_back(p[i]);
    }

    PRINTLN(hull.size());

    return 0;
}
