#include <iostream>

using namespace std;
using pii = pair<int, int>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    pii p[3];
    int ccw = 0;

    for (auto &pi : p) {
        cin >> pi.F >> pi.S;
    }

    REP(i, 3) {ccw += p[i].F * p[(i + 1) % 3].S - p[i].S * p[(i + 1) % 3].F;

    PRINTLN(ccw > 0 ? 1 : ccw < 0 ? -1 : 0);

    return 0;
}
