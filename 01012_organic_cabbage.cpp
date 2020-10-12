#include <cstring>
#include <iostream>
#include <queue>

#define MAX_SIZE 50

using namespace std;

typedef struct Point {
    int y;
    int x;
} Point;

Point operator+(Point point1, Point point2) {
    return {point1.y + point2.y, point1.x + point2.x};
}

int n;
int m;
int map[MAX_SIZE][MAX_SIZE];
int cabbageChunkNoAt[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{0,  -1},
                             {1,  0},
                             {-1, 0},
                             {0,  1}};

void bfsCabbageChunk(Point point, int cabbageChunkNo) {
    queue<Point> bfsPoints;

    cabbageChunkNoAt[point.y][point.x] = cabbageChunkNo;

    bfsPoints.push(point);

    while (!bfsPoints.empty()) {
        point = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacentPoint = point + difference;

            if (adjacentPoint.y < 0 || adjacentPoint.y >= n || adjacentPoint.x < 0 || adjacentPoint.x >= m) continue;

            if (map[adjacentPoint.y][adjacentPoint.x] && !cabbageChunkNoAt[adjacentPoint.y][adjacentPoint.x]) {
                cabbageChunkNoAt[adjacentPoint.y][adjacentPoint.x] = cabbageChunkNo;

                bfsPoints.push(adjacentPoint);
            }
        }
    }
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int numCabbage;
        int cabbageChunkCount = 0;

        cin >> m >> n >> numCabbage;

        while (numCabbage-- > 0) {
            int y;
            int x;

            cin >> x >> y;

            map[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] && !cabbageChunkNoAt[i][j]) bfsCabbageChunk({i, j}, ++cabbageChunkCount);
            }
        }

        cout << cabbageChunkCount << '\n';

        memset(map, 0, sizeof(map));
        memset(cabbageChunkNoAt, 0, sizeof(cabbageChunkNoAt));
    }

    return 0;
}
