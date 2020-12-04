#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int vertexAt[50][50];

int main() {
    int n;
    vector<pair<int, int>> vertexPoints;
    int vertexPointsSize = 0;
    int startVertex = -1;
    int finishVertex = -1;
    queue<int> bfsVertices;

    cin >> n;

    vector<string> map(n);

    for (int i = 0; i < n; i++) {
        cin >> map[i];

        for (int j = 0; j < n; j++) {
            if (map[i][j] == '#') (startVertex == -1 ? startVertex : finishVertex) = vertexPointsSize;

            if (map[i][j] == '!' || map[i][j] == '#') {
                vertexAt[i][j] = vertexPointsSize;
                vertexPointsSize++;

                vertexPoints.emplace_back(i, j);
            }
        }
    }

    vector<vector<int>> adjacentVerticesOf(vertexPointsSize);
    vector<int> degrees(vertexPointsSize, -1);

    for (int i = 0; i < vertexPointsSize; i++) {
        int y;
        int x;

        tie(y, x) = vertexPoints[i];

        for (int j = 0; j < 4; j++) {
            int distance = 1;

            while (true) {
                int ny = y + distance * ("1201"[j] - '1');
                int nx = x + distance * ("0112"[j] - '1');

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == '*') break;

                if (map[ny][nx] != '.') adjacentVerticesOf[i].push_back(vertexAt[ny][nx]);

                distance++;
            }
        }
    }

    degrees[startVertex] = 0;

    bfsVertices.push(startVertex);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (degrees[adjacentVertex] == -1) {
                degrees[adjacentVertex] = degrees[currentVertex] + 1;

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    cout << degrees[finishVertex] - 1 << '\n';

    return 0;
}
