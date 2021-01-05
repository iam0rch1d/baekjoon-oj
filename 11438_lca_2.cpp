#include <cstring>
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
#define RESET(arr, x) memset(arr, x, sizeof(arr))

#define SIZE 100001

vi adjacentVerticesOf[SIZE];
int depths[SIZE];
int dpAncestor[SIZE][17];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    REP(i, n - 1) {
        int x;
        int y;

        cin >> x >> y;

        adjacentVerticesOf[x].push_back(y);
        adjacentVerticesOf[y].push_back(x);
    }

    RESET(depths, -1);

    queue<int> bfsVertices;

    depths[1] = 0;

    bfsVertices.push(1);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (depths[adjacentVertex] == -1) {
                depths[adjacentVertex] = depths[currentVertex] + 1;
                dpAncestor[adjacentVertex][0] = currentVertex;  // Parent

                bfsVertices.push(adjacentVertex);
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

        int power = 0;

        while ((1 << power) <= depths[u]) power++;

        IFOR(i, 0, power) if (depths[u] - (1 << i) >= depths[v]) u = dpAncestor[u][i];

        if (u == v) return u;

        IFOR(i, 0, power) {
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

        PRINTLN(lca(u, v));
    }

    return 0;
}
