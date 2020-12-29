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

#define INF 1000000001

int main() {
    int n;
    int m;

    cin >> n >> m;

    vvi degrees(n, vi(n, INF));

    REP(i, n) degrees[i][i] = 0;

    while (m--) {
        int a;
        int b;

        cin >> a >> b;

        a--;
        b--;

        degrees[a][b] = 1;
        degrees[b][a] = 1;
    }

    REP(aux, n) REP(from, n) REP(to, n) chmin(degrees[from][to], degrees[from][aux] + degrees[aux][to]);

    int ans = -1;
    int minBacon = INF;

    REP(i, n) {
        int bacon = 0;

        REP(j, n) bacon += degrees[i][j];

        if (chmin(minBacon, bacon)) ans = i;
    }

    PRINTLN(ans + 1);

    return 0;
}
