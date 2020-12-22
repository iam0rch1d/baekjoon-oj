#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using pib = pair<int, bool>;
using vpib = vector<pib>;

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

    vpib points;

    while (n--) {
        int start;
        int end;

        cin >> start >> end;

        points.emplace_back(start, true);
        points.emplace_back(end, false);
    }

    sort(ALL(points));

    int pointsSize = points.size();
    int overlaps = 0;
    int ans = 0;

    REP(i, pointsSize) {
        if (points[i].S) overlaps++;
        else overlaps--;

        ans = max(ans, overlaps);
    }

    PRINTLN(ans);

    return 0;
}
