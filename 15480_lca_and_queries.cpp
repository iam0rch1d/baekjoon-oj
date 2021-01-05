#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vi>;

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define SIZE 100001

vi adjacentVerticesOf[SIZE];
int power;
int tick;
int depths[SIZE];
int dpAncestor[SIZE][17];
int tin[SIZE];
int tout[SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    REP(i, n - 1) {
        int u;
        int v;

        cin >> u >> v;

        adjacentVerticesOf[u].push_back(v);
        adjacentVerticesOf[v].push_back(u);
    }

    while ((1 << power) <= n) power++;

    function<void(int, int)> dfsVertices = [&](int vertex, int parent) {
        tin[vertex] = ++tick;

        dpAncestor[vertex][0] = parent;

        FOR(i, 1, power) dpAncestor[vertex][i] = dpAncestor[dpAncestor[vertex][i - 1]][i - 1];

        for (int adjacentVertex : adjacentVerticesOf[vertex]) {
            if (adjacentVertex != parent) {
                depths[adjacentVertex] = depths[vertex] + 1;

                dfsVertices(adjacentVertex, vertex);
            }
        }

        tout[vertex] = ++tick;
    };

    dfsVertices(1, 1);

    auto isAncestor = [&](int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    auto lca = [&](int u, int v) {
        if (isAncestor(u, v)) return u;

        if (isAncestor(v, u)) return v;

        IFOR(i, 0, power) if (!isAncestor(dpAncestor[u][i], v)) u = dpAncestor[u][i];

        return dpAncestor[u][0];
    };

    auto distance = [&](int u, int v) {
        return depths[u] + depths[v] - 2 * depths[lca(u, v)];
    };

    int m;

    cin >> m;

    while (m--) {
        int r;
        int u;
        int v;

        cin >> r >> u >> v;

        vpii candidates{{0, r}, {0, u}, {0, v}, {0, lca(r, u)}, {0, lca(u, v)}, {0, lca(v, r)}};

        for (pii &candidate : candidates) {
            candidate.F = distance(candidate.S, r) + distance(candidate.S, u) + distance(candidate.S, v);
        }

        sort(ALL(candidates));
        PRINTLN(candidates[0].S);
    }

    return 0;
}
