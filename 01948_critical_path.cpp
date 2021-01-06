#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;

#define F first
#define S second
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

vpii forwardEdgesOf[10000];
vpii reverseEdgesOf[10000];
int forwardIndegrees[10000];
int reverseIndegrees[10000];
int dist[10000];
bool isCritical[10000];

int main() {
    int n;
    int m;

    cin >> n >> m;

    while (m--) {
        int fromVertex;
        int toVertex;
        int cost;

        cin >> fromVertex >> toVertex >> cost;

        fromVertex--;
        toVertex--;

        forwardEdgesOf[fromVertex].emplace_back(toVertex, cost);
        reverseEdgesOf[toVertex].emplace_back(fromVertex, cost);

        forwardIndegrees[toVertex]++;
        reverseIndegrees[fromVertex]++;
    }

    int startVertex;
    int finishVertex;

    cin >> startVertex >> finishVertex;

    startVertex--;
    finishVertex--;

    queue<int> bfsVertices;

    bfsVertices.push(startVertex);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (pii edge : forwardEdgesOf[currentVertex]) {
            chmax(dist[edge.F], dist[currentVertex] + edge.S);

            if (--forwardIndegrees[edge.F] == 0) bfsVertices.push(edge.F);
        }
    }

    PRINTLN(dist[finishVertex]);

    int ans = 0;

    isCritical[finishVertex] = true;

    bfsVertices.push(finishVertex);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (pii edge : reverseEdgesOf[currentVertex]) {
            if (isCritical[currentVertex] && dist[currentVertex] - dist[edge.F] == edge.S) {
                isCritical[edge.F] = true;
                ans++;
            }

            if (--reverseIndegrees[edge.F] == 0) bfsVertices.push(edge.F);
        }
    }

    PRINTLN(ans);

    return 0;
}
