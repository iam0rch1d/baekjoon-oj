#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
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

    vvi distances(n + 1, vi(n + 1, INF));

    FOR_(i, 1, n) distances[i][i] = 0;

    vvi forwards(n + 1, vi(n + 1, -1));

    while (m--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        if (chmin(distances[a][b], c)) forwards[a][b] = b;
    }

    FOR_(aux, 1, n) {
        FOR_(from, 1, n) {
            FOR_(to, 1, n) {
                if (chmin(distances[from][to], distances[from][aux] + distances[aux][to])) {
                    forwards[from][to] = forwards[from][aux];
                }
            }
        }
    }

    FOR_(i, 1, n) {
        FOR_(j, 1, n) PRINT(distances[i][j]);

        PRINTLN("");
    }

    auto traceforward = [=](int from, int to) {
        queue<int> traceforwardVertices;

        if (forwards[from][to] == -1) {
            PRINTLN(0);

            return;
        }

        traceforwardVertices.push(from);

        while (from != to) {
            from = forwards[from][to];

            traceforwardVertices.push(from);
        }

        PRINT(traceforwardVertices.size());

        while (!traceforwardVertices.empty()) {
            PRINT(traceforwardVertices.front());

            traceforwardVertices.pop();
        }

        PRINTLN("");
    };

    FOR_(i, 1, n) {
        FOR_(j, 1, n) {
            if (i == j || distances[i][j] == INF) PRINTLN(0);
            else traceforward(i, j);
        }
    }

    return 0;
}
