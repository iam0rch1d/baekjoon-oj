#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

using pii = pair<int, int>;

#define PRINTLN(x) cout << (x) << '\n'

int dist[500001][2];

int main() {
    int n;
    int k;
    queue<pii> bfsVertices;

    cin >> n >> k;

    dist[n][0] = 1;

    bfsVertices.emplace(n, 0);

    while (!bfsVertices.empty()) {
        int x;
        int t;

        tie(x, t) = bfsVertices.front();

        bfsVertices.pop();

        for (int nx : {2 * x, x + 1, x - 1}) {
            if (nx <= 0 || nx > 500000 || dist[nx][1 - t]) continue;

            dist[nx][1 - t] = dist[x][t] + 1;

            bfsVertices.emplace(nx, 1 - t);
        }
    }

    int t = 0;

    while (k <= 500000) {
        if (dist[k][t % 2] - 1 <= t) {
            PRINTLN(t);

            return 0;
        }

        k += ++t;
    }

    PRINTLN(-1);

    return 0;
}
