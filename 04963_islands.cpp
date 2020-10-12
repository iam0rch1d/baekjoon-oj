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

int h;
int w;
int map[MAX_SIZE][MAX_SIZE];
int landNoAt[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{-1, -1},
                             {-1, 0},
                             {-1, 1},
                             {0,  -1},
                             {0,  1},
                             {1,  -1},
                             {1,  0},
                             {1,  1}};

void bfsLand(Point point, int landNo) {
    queue<Point> bfsPoints;

    landNoAt[point.y][point.x] = landNo;

    bfsPoints.push(point);

    while (!bfsPoints.empty()) {
        point = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacentPoint = point + difference;

            if (adjacentPoint.y < 0 || adjacentPoint.y >= h || adjacentPoint.x < 0 || adjacentPoint.x >= w) continue;

            if (map[adjacentPoint.y][adjacentPoint.x] && !landNoAt[adjacentPoint.y][adjacentPoint.x]) {
                landNoAt[adjacentPoint.y][adjacentPoint.x] = landNo;

                bfsPoints.push(adjacentPoint);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int landCount = 0;

        cin >> w >> h;

        if (w == 0 && h == 0) return 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] && !landNoAt[i][j]) bfsLand({i, j}, ++landCount);
            }
        }

        cout << landCount << '\n';

        memset(map, 0, sizeof(map));
        memset(landNoAt, 0, sizeof(landNoAt));
    }
}
