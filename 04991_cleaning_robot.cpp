#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int w;
        int h;
        vector<pair<int, int>> vertexPoints;
        int vertexPointsSize = 0;
        int startVertex = -1;
        queue<int> bfsVertices;
        bool canVisitAll = true;
        int minTotalWeight = 4001;

        cin >> w >> h;

        if (!w && !h) {
            return 0;
        }

        vector<string> map(h);
        vector<vector<int>> vertexAt(h, vector<int>(w, -1));

        for (int i = 0; i < h; i++) {
            cin >> map[i];

            for (int j = 0; j < w; j++) {
                if (map[i][j] == 'o') startVertex = vertexPointsSize;

                if (map[i][j] == '*' || map[i][j] == 'o') {
                    vertexAt[i][j] = vertexPointsSize;
                    vertexPointsSize++;

                    vertexPoints.emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> weights(vertexPointsSize, vector<int>(vertexPointsSize, 0));
        vector<int> visitingOrders(1, startVertex);

        for (int i = 0; i < vertexPointsSize; i++) {
            if (i == startVertex) continue;

            visitingOrders.push_back(i);
        }

        for (int i = 0; i < vertexPointsSize; i++) {
            int sy;
            int sx;
            vector<vector<int>> distances(h, vector<int>(w, -1));
            queue<pair<int, int>> bfsPoints;

            tie(sy, sx) = vertexPoints[i];

            distances[sy][sx] = 0;

            bfsPoints.push(vertexPoints[i]);

            while (!bfsPoints.empty()) {
                int y;
                int x;

                tie(y, x) = bfsPoints.front();

                bfsPoints.pop();

                for (int j = 0; j < 4; j++) {
                    int ny = y + "1201"[j] - '1';
                    int nx = x + "0112"[j] - '1';

                    if (ny < 0 || ny >= h || nx < 0 || nx >= w || map[ny][nx] == 'x' || distances[ny][nx] != -1) {
                        continue;
                    }

                    distances[ny][nx] = distances[y][x] + 1;

                    if (vertexAt[ny][nx] != -1) {
                        weights[i][vertexAt[ny][nx]] = distances[ny][nx];
                    }

                    bfsPoints.push({ny, nx});
                }
            }
        }

        for (int i = 0; i < vertexPointsSize; i++) {
            for (int j = 0; j < vertexPointsSize; j++) {
                if (i != j && !weights[i][j]) canVisitAll = false;
            }
        }

        if (!canVisitAll) {
            cout << "-1\n";

            continue;
        }

        while (true) {
            int totalWeight = 0;

            for (int i = 1; i < vertexPointsSize; i++) {
                totalWeight += weights[visitingOrders[i - 1]][visitingOrders[i]];
            }

            minTotalWeight = min(minTotalWeight, totalWeight);

            if (!next_permutation(visitingOrders.begin() + 1, visitingOrders.end())) break;
        }

        cout << minTotalWeight << '\n';
    }
}
