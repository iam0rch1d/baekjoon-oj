#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vvi adjacentVerticesOf(n + 1);

    REP(i, n - 1) {
        int x;
        int y;

        cin >> x >> y;

        adjacentVerticesOf[x].push_back(y);
        adjacentVerticesOf[y].push_back(x);
    }

    vi depths(n + 1, -1);
    vvi ancestorsOf(n + 1, vi(17, 0));
    queue<int> bfsVertices;

    depths[1] = 0;

    bfsVertices.push(1);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (depths[adjacentVertex] == -1) {
                depths[adjacentVertex] = depths[currentVertex] + 1;
                ancestorsOf[adjacentVertex][0] = currentVertex;  // Parent

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    for (int j = 1; (1 << j) <= n; j++) {
        FOR_(i, 1, n) if (ancestorsOf[i][j - 1]) ancestorsOf[i][j] = ancestorsOf[ancestorsOf[i][j - 1]][j - 1];
    }

    int m;

    cin >> m;

    auto lca = [&](int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);

        int logDepth = 0;

        while ((1 << logDepth) <= depths[u]) logDepth++;

        IFOR(i, 0, logDepth) if (depths[u] - (1 << i) >= depths[v]) u = ancestorsOf[u][i];

        if (u == v) return u;

        IFOR(i, 0, logDepth) {
            if (ancestorsOf[u][i] && ancestorsOf[u][i] != ancestorsOf[v][i]) {
                u = ancestorsOf[u][i];
                v = ancestorsOf[v][i];
            }
        }

        return ancestorsOf[u][0];
    };

    while (m--) {
        int u;
        int v;

        cin >> u >> v;

        PRINTLN(lca(u, v));
    }

    return 0;
}
