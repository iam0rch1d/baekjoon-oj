#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define PRINTLN(x) cout << (x) << '\n'

struct Edge {
    int fromVertex;
    int toVertex;
    int weight;

    bool operator<(Edge &q) const { return weight < q.weight; }
};

int main() {
    int v;
    int e;

    cin >> v >> e;

    vector<Edge> edges(e);

    for (Edge &edge : edges) {
        cin >> edge.fromVertex >> edge.toVertex >> edge.weight;
    }

    sort(ALL(edges));

    vector<int> parents(v + 1, -1);

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

    for (Edge edge : edges) {
        if (ufUnion(edge.fromVertex, edge.toVertex)) ans += edge.weight;
    }

    PRINTLN(ans);

    return 0;
}
