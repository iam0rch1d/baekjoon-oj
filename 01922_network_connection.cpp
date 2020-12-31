#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define PRINTLN(x) cout << (x) << '\n'

struct Edge {
    int toVertex;
    int cost;

    bool operator>(Edge &q) const { return cost > q.cost; }
};

vector<Edge> adjacentEdgesOf[1001];
bool isVisited[1001];

int main() {
    int n;
    int m;

    cin >> n >> m;

    while (m--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        adjacentEdgesOf[a].push_back({b, c});
        adjacentEdgesOf[b].push_back({a, c});
    }

    priority_queue<Edge, vector<Edge>, greater<>> bfsEdges;
    int ans = 0;

    isVisited[1] = true;

    for (Edge adjacentEdge : adjacentEdgesOf[1]) {
        bfsEdges.push(adjacentEdge);
    }

    while (!bfsEdges.empty()) {
        auto current = bfsEdges.top();

        bfsEdges.pop();

        if (isVisited[current.toVertex]) continue;

        isVisited[current.toVertex] = true;
        ans += current.cost;

        for (Edge adjacentEdge : adjacentEdgesOf[current.toVertex]) {
            bfsEdges.push(adjacentEdge);
        }
    }

    PRINTLN(ans);

    return 0;
}
