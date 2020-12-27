#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
T square(T x) { return x * x; }

template<typename T>
T euclidean(pair<T, T> a, pair<T, T> b) { return square(b.F - a.F) + square(b.S - a.S); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vpll p(n);

    for (pll &pi : p) {
        cin >> pi.F >> pi.S;
    }

    sort(ALL(p));

    ll ans = euclidean(p[0], p[1]);
    auto yCompare = [](pll i, pll j) { return i.S < j.S || (i.S == j.S && i.F < j.F); };
    set<pll, decltype(yCompare)> candidate(yCompare);
    int xLowerBoundIndex = 0;

    candidate.insert(p[0]);
    candidate.insert(p[1]);

    FOR(i, 2, n) {
        pll current = p[i];

        while (xLowerBoundIndex < i) {
            if (square(current.F - p[xLowerBoundIndex].F) > ans) {
                candidate.erase(p[xLowerBoundIndex]);

                xLowerBoundIndex++;
            } else break;
        }

        ll dy = (ll) sqrt((double) ans) + 1;

        auto yLowerBound = candidate.lower_bound({-123456, current.S - dy});
        auto yUpperBound = candidate.upper_bound({123456, current.S + dy});

        for (auto head = yLowerBound; head != yUpperBound; head++) {
            ans = min(ans, euclidean(current, *head));
        }

        candidate.insert(current);
    }

    PRINTLN(ans);

    return 0;
}
