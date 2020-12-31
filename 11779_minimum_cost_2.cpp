#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 100000000

struct Edge {
    int toVertex;
    int cost;
};

vector<Edge> edgesOf[100000];
bool isVisited[100000];

int main() {
    int n;
    int m;

    cin >> n >> m;

    REP(i, m) {
        int fromVertex;
        int toVertex;
        int cost;

        cin >> fromVertex >> toVertex >> cost;

        fromVertex--;
        toVertex--;

        edgesOf[fromVertex].push_back({toVertex, cost});
    }

    int startVertex;
    int finishVertex;

    cin >> startVertex >> finishVertex;

    startVertex--;
    finishVertex--;

    vi distances(n, INF);
    priority_queue<pii> dijkstraVertices;
    vi backVertices(n, -1);

    distances[startVertex] = 0;

    dijkstraVertices.push({0, startVertex});

    while (!dijkstraVertices.empty()) {
        int vertex = dijkstraVertices.top().S;

        dijkstraVertices.pop();

        if (isVisited[vertex]) continue;

        isVisited[vertex] = true;

        for (auto edge : edgesOf[vertex]) {
            int toVertex = edge.toVertex;
            int cost = edge.cost;

            if (chmin(distances[toVertex], distances[vertex] + cost)) {
                dijkstraVertices.push({-distances[toVertex], toVertex});

                backVertices[toVertex] = vertex;
            }
        }
    }

    PRINTLN(distances[finishVertex]);

    stack<int> traceback;
    int tracebackSize = 0;

    while (finishVertex != -1) {
        traceback.push(finishVertex + 1);

        finishVertex = backVertices[finishVertex];
        tracebackSize++;
    }

    PRINTLN(tracebackSize);

    while (!traceback.empty()) {
        PRINT(traceback.top());
        traceback.pop();
    }

    return 0;
}
