#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vpii points;

    while (n--) {
        int start;
        int end;

        cin >> start >> end;

        points.emplace_back(start, 1);
        points.emplace_back(end, -1);
    }

    sort(ALL(points));

    int pointsSize = points.size();
    int lineStack = 0;
    int lineStart = 0;
    int ans = 0;

    REP(i, pointsSize) {
        if (!lineStack) lineStart = points[i].F;

        lineStack += points[i].S;

        if (!lineStack) ans += points[i].F - lineStart;
    }

    PRINTLN(ans);

    return 0;
}
