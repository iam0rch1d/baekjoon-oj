#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;

    cin >> n >> k;

    vvi d(n, vi(n, INF));

    while (k--) {
        int before;
        int after;

        cin >> before >> after;

        --before;
        --after;

        d[before][after] = 0;
    }

    REP(aux, n) REP(from, n) REP(to, n) chmin(d[from][to], d[from][aux] + d[aux][to]);

    int s;

    cin >> s;

    while (s--) {
        int x;
        int y;

        cin >> x >> y;

        --x;
        --y;

        if (!d[x][y] && d[y][x]) PRINTLN(-1);
        else if (!d[y][x] && d[x][y]) PRINTLN(1);
        else PRINTLN(0);
    }

    return 0;
}
