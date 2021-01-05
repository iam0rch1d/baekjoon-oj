#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define SIZE 100001

vi adjacentVerticesOf[SIZE];
int power;
int tick;
int dpAncestor[SIZE][17];
int tin[SIZE];
int tout[SIZE];

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

    while ((1 << power) <= n) power++;

    function<void(int, int)> dfsVertices = [&](int vertex, int parent) {
        tin[vertex] = ++tick;

        dpAncestor[vertex][0] = parent;

        FOR(i, 1, power) dpAncestor[vertex][i] = dpAncestor[dpAncestor[vertex][i - 1]][i - 1];

        for (int adjacentVertex : adjacentVerticesOf[vertex]) {
            if (adjacentVertex != parent) dfsVertices(adjacentVertex, vertex);
        }

        tout[vertex] = ++tick;
    };

    dfsVertices(1, 1);

    auto isAncestor = [&](int m, int q) {
        return tin[m] <= tin[q] && tout[m] >= tout[q];
    };

    auto lca = [&](int u, int v) {
        if (isAncestor(u, v)) return u;

        if (isAncestor(v, u)) return v;

        IFOR(i, 0, power) if (!isAncestor(dpAncestor[u][i], v)) u = dpAncestor[u][i];

        return dpAncestor[u][0];
    };

    int m;

    cin >> m;

    while (m--) {
        int u;
        int v;

        cin >> u >> v;

        PRINTLN(lca(u, v));
    }

    return 0;
}
