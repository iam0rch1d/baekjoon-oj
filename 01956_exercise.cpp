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

#define INF 987654321

int main() {
    int v;
    int e;

    cin >> v >> e;

    vvi d(v, vi(v, INF));

    while (e--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        --a;
        --b;

        d[a][b] = c;
    }

    REP(aux, v) REP(from, v) REP(to, v) chmin(d[from][to], d[from][aux] + d[aux][to]);

    int ans = INF;

    REP(i, v) chmin(ans, d[i][i]);

    PRINTLN(ans == INF ? -1 : ans);

    return 0;
}
