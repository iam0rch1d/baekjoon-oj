#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using vi = vector<int>;

#define ALL(x) x.begin(), x.end()
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);  // (cost, fromVertex, toVertex)

    for (auto &edge : edges) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        edge = {c, a, b};
    }

    sort(ALL(edges));

    vi parents(n, -1);

    auto ufFind = [&](int x) {
        while (parents[x] >= 0) {
            if (parents[parents[x]] >= 0) parents[x] = parents[parents[x]];

            x = parents[x];
        }

        return x;
    };

    auto ufUnion = [&](int x, int y) {
        x = ufFind(x);
        y = ufFind(y);

        if (x == y) return false;

        if (parents[x] > parents[y]) swap(x, y);

        parents[x] += parents[y];
        parents[y] = x;

        return true;
    };

    int ans = 0;
    int edgeCount = 0;

    for (auto edge : edges) {
        int cost;
        int fromVertex;
        int toVertex;

        tie(cost, fromVertex, toVertex) = edge;

        if (ufUnion(fromVertex, toVertex)) {
            ans += cost;
            edgeCount++;
        }

        if (edgeCount == n - 2) break;
    }

    PRINTLN(ans);

    return 0;
}
