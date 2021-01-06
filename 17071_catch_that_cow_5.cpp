#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

#define PRINTLN(x) cout << (x) << '\n'

int distances[500001][2];

int main() {
    int n;
    int k;
    queue<pii> bfsVertices;

    cin >> n >> k;

    distances[n][0] = 1;

    bfsVertices.push({n, 0});

    while (!bfsVertices.empty()) {
        int x;
        int t;

        tie(x, t) = bfsVertices.front();

        bfsVertices.pop();

        for (int nx : {2 * x, x + 1, x - 1}) {
            if (nx <= 0 || nx > 500000 || distances[nx][1 - t]) continue;

            distances[nx][1 - t] = distances[x][t] + 1;

            bfsVertices.push({nx, 1 - t});
        }
    }

    int t = 0;

    while (k <= 500000) {
        if (distances[k][t % 2] - 1 <= t) {
            PRINTLN(t);

            return 0;
        }

        k += ++t;
    }

    PRINTLN(-1);

    return 0;
}
