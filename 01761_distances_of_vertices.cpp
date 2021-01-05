#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vi>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

vpii adjacentVerticesOf[40001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    REP(i, n - 1) {
        int x;
        int y;
        int distance;

        cin >> x >> y >> distance;

        adjacentVerticesOf[x].emplace_back(y, distance);
        adjacentVerticesOf[y].emplace_back(x, distance);
    }

    vi depths(n + 1, -1);
    vvi dpAncestor(n + 1, vi(16, 0));
    vi distances(n + 1, -1);
    queue<int> bfsVertices;

    depths[1] = 0;
    distances[1] = 0;

    bfsVertices.push(1);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (auto adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (depths[adjacentVertex.F] == -1) {
                depths[adjacentVertex.F] = depths[currentVertex] + 1;
                dpAncestor[adjacentVertex.F][0] = currentVertex;
                distances[adjacentVertex.F] = distances[currentVertex] + adjacentVertex.S;

                bfsVertices.push(adjacentVertex.F);
            }
        }
    }

    for (int j = 1; (1 << j) <= n; j++) {
        FOR_(i, 1, n) if (dpAncestor[i][j - 1]) dpAncestor[i][j] = dpAncestor[dpAncestor[i][j - 1]][j - 1];
    }

    int m;

    cin >> m;

    auto lca = [&](int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);

        int logDepth = 0;

        while ((1 << logDepth) <= depths[u]) logDepth++;

        IFOR(i, 0, logDepth) if (depths[u] - (1 << i) >= depths[v]) u = dpAncestor[u][i];

        if (u == v) return u;

        IFOR(i, 0, logDepth) {
            if (dpAncestor[u][i] && dpAncestor[u][i] != dpAncestor[v][i]) {
                u = dpAncestor[u][i];
                v = dpAncestor[v][i];
            }
        }

        return dpAncestor[u][0];
    };

    while (m--) {
        int u;
        int v;

        cin >> u >> v;

        PRINTLN(distances[u] + distances[v] - 2 * distances[lca(u, v)]);
    }

    return 0;
}
