#include <algorithm>
#include <iostream>
#include <queue>

#define MAX_SIZE 30

using namespace std;

typedef struct Point {
    int y;
    int x;
} Point;

Point operator+(Point point1, Point point2) {
    return {point1.y + point2.y, point1.x + point2.x};
}

int n;
int map[MAX_SIZE][MAX_SIZE];
int buildingNoAt[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{0,  -1},
                             {1,  0},
                             {-1, 0},
                             {0,  1}};
int buildingCounts[MAX_SIZE * MAX_SIZE / 2 + MAX_SIZE];

void bfsBuilding(Point point, int buildingNo) {
    queue<Point> bfsPoints;

    buildingNoAt[point.y][point.x] = buildingNo;

    bfsPoints.push(point);

    while (!bfsPoints.empty()) {
        point = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacentPoint = point + difference;

            if (adjacentPoint.y < 0 || adjacentPoint.y >= n || adjacentPoint.x < 0 || adjacentPoint.x >= n) continue;

            if (map[adjacentPoint.y][adjacentPoint.x] && !buildingNoAt[adjacentPoint.y][adjacentPoint.x]) {
                buildingNoAt[adjacentPoint.y][adjacentPoint.x] = buildingNo;

                bfsPoints.push(adjacentPoint);
            }
        }
    }
}

int main() {
    int buildingNo = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < n; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] && !buildingNoAt[i][j]) bfsBuilding({i, j}, ++buildingNo);
        }
    }

    cout << buildingNo << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buildingCounts[buildingNoAt[i][j]]++;
        }
    }

    sort(buildingCounts + 1, buildingCounts + buildingNo + 1);

    for (int i = 1; i <= buildingNo; i++) {
        cout << buildingCounts[i] << '\n';
    }

    return 0;
}
