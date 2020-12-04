#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

int n;
int m;
int map[MAX_SIZE][MAX_SIZE];
int shapeNoAt[MAX_SIZE][MAX_SIZE];
vector<int> shapeAreas;

void bfsShapeNo(int sy, int sx, int shapeNo) {
    queue<pair<int, int>> bfsPoints;
    int shapeArea = 1;

    shapeNoAt[sy][sx] = shapeNo;

    bfsPoints.push({sy, sx});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || !map[ny][nx] || shapeNoAt[ny][nx]) continue;

            shapeNoAt[ny][nx] = shapeNo;
            shapeArea++;

            bfsPoints.push({ny, nx});
        }
    }

    shapeAreas.push_back(shapeArea);
}

int main() {
    int shapeNo = 0;
    int maxTotalShapeArea = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    shapeAreas.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] && !shapeNoAt[i][j]) bfsShapeNo(i, j, ++shapeNo);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j]) {
                set<int> adjacentShapes;
                int totalShapeArea = 1;

                for (int k = 0; k < 4; k++) {
                    int ni = i + "1201"[k] - '1';
                    int nj = j + "0112"[k] - '1';

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || !map[ni][nj]) continue;

                    adjacentShapes.insert(shapeNoAt[ni][nj]);
                }

                for (int adjacentShapeNo : adjacentShapes) {
                    totalShapeArea += shapeAreas[adjacentShapeNo];
                }

                maxTotalShapeArea = max(maxTotalShapeArea, totalShapeArea);
            }
        }
    }

    cout << maxTotalShapeArea << '\n';

    return 0;
}
