#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
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

    vi a;  // DFS visiting orders
    vi depths;

    function<void(int, int, int)> dfs = [&](int vertex, int parent, int depth) {
        a.push_back(vertex);
        depths.push_back(depth);

        for (int adjacentVertex : adjacentVerticesOf[vertex]) {
            if (adjacentVertex == parent) continue;

            dfs(adjacentVertex, vertex, depth + 1);
            a.push_back(vertex);
            depths.push_back(depth);
        }
    };

    dfs(1, 0, 0);

    vi appearances(n + 1, -1);

    n = a.size();

    REP(i, n) {
        int node = a[i];

        if (appearances[node] == -1) appearances[node] = i;
    }

    int height = (int) ceil(log2(n)) + 1;
    vi segtree(1 << height);

    function<void(int, int, int)> init = [&](int node, int left, int right) {
        if (left == right) {
            segtree[node] = left;

            return;
        }

        int mid = (left + right) / 2;
        int leftChild = node * 2;
        int rightChild = leftChild + 1;

        init(leftChild, left, mid);
        init(rightChild, mid + 1, right);

        if (depths[segtree[leftChild]] < depths[segtree[rightChild]]) segtree[node] = segtree[leftChild];
        else segtree[node] = segtree[rightChild];
    };

    init(1, 0, n - 1);

    function<int(int, int, int, int, int)> query = [&](int node, int left, int right, int x, int y) -> int {
        // Get visiting order with minimum depth
        if (x > right || y < left) return -1;
        else if (x <= left && y >= right) return segtree[node];

        int mid = (left + right) / 2;
        int leftChildQuery = query(node * 2, left, mid, x, y);
        int rightChildQuery = query(node * 2 + 1, mid + 1, right, x, y);

        if (leftChildQuery == -1) return rightChildQuery;
        else if (rightChildQuery == -1) return leftChildQuery;
        else return depths[leftChildQuery] < depths[rightChildQuery] ? leftChildQuery : rightChildQuery;
    };

    int m;

    cin >> m;

    while (m--) {
        int u;
        int v;

        cin >> u >> v;

        int x = appearances[u];
        int y = appearances[v];

        if (x > y) swap(x, y);

        PRINTLN(a[query(1, 0, n - 1, x, y)]);
    }

    return 0;
}
