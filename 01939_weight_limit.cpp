#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> adjacentVerticesOf[10001];  // (<vertex no.>, <weight limit>)
int fromFactory;
int toFactory;

bool canLoad(int weight) {
    vector<bool> isVisited(n + 1, false);
    queue<int> bfsVertices;

    isVisited[fromFactory] = true;

    bfsVertices.push(fromFactory);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        if (currentVertex == toFactory) return true;

        bfsVertices.pop();

        for (auto adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (!isVisited[adjacentVertex.first] && adjacentVertex.second >= weight) {
                isVisited[adjacentVertex.first] = true;

                bfsVertices.push(adjacentVertex.first);
            }
        }
    }

    return false;
}

int main() {
    int m;
    int weightLimitLeft = 1e9 + 1;
    int weightLimitRight = 0;
    int weightLimit;

    cin >> n >> m;

    while (m--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        if (weightLimitLeft > c) weightLimitLeft = c;

        if (weightLimitRight < c) weightLimitRight = c;

        adjacentVerticesOf[a].emplace_back(b, c);
        adjacentVerticesOf[b].emplace_back(a, c);
    }

    cin >> fromFactory >> toFactory;

    while (weightLimitLeft <= weightLimitRight) {
        int weightLimitMid = (weightLimitLeft + weightLimitRight) / 2;

        if (canLoad(weightLimitMid)) {
            weightLimit = weightLimitMid;
            weightLimitLeft = weightLimitMid + 1;
        } else weightLimitRight = weightLimitMid - 1;
    }

    cout << weightLimit << '\n';

    return 0;
}
