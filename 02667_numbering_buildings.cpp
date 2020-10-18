#include <algorithm>
#include <iostream>
#include <queue>

#define MAX_SIZE 30

using namespace std;

typedef struct Point {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int n;
int map[MAX_SIZE][MAX_SIZE];
int buildingNoAt[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{0,  -1},
                             {1,  0},
                             {-1, 0},
                             {0,  1}};
int buildingCounts[MAX_SIZE * MAX_SIZE / 2 + MAX_SIZE];

void bfsBuildingNo(Point current, int buildingNo) {
    queue<Point> bfsPoints;

    buildingNoAt[current.y][current.x] = buildingNo;

    bfsPoints.push(current);

    while (!bfsPoints.empty()) {
        current = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= n) continue;

            if (map[adjacent.y][adjacent.x] && !buildingNoAt[adjacent.y][adjacent.x]) {
                buildingNoAt[adjacent.y][adjacent.x] = buildingNo;

                bfsPoints.push(adjacent);
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
            if (map[i][j] && !buildingNoAt[i][j]) bfsBuildingNo({i, j}, ++buildingNo);
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
