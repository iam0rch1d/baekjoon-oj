#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 1000000001

int main() {
    int n;
    int m;

    cin >> n >> m;

    vvi distances(n, vi(n, INF));

    REP(i, n) distances[i][i] = 0;

    while (m--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        a--;
        b--;

        chmin(distances[a][b], c);
    }

    REP(aux, n) REP(from, n) REP(to, n) chmin(distances[from][to], distances[from][aux] + distances[aux][to]);

    REP(i, n) {
        REP(j, n) PRINT(distances[i][j] == INF ? 0 : distances[i][j]);

        PRINTLN("");
    }

    return 0;
}
