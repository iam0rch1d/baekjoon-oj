#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

#define MAX_SIZE 100

int n;
int map[MAX_SIZE][MAX_SIZE];
int islandNoAt[MAX_SIZE][MAX_SIZE];
int distanceTo[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{-1, 0},
                             {0,  1},
                             {0,  -1},
                             {1,  0}};

void bfsIslandNo(Point current, int islandNo) {
    queue<Point> bfsIslandPoints;

    islandNoAt[current.y][current.x] = islandNo;

    bfsIslandPoints.push(current);

    while (!bfsIslandPoints.empty()) {
        current = bfsIslandPoints.front();

        bfsIslandPoints.pop();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= n) continue;

            if (map[adjacent.y][adjacent.x] && !islandNoAt[adjacent.y][adjacent.x]) {
                islandNoAt[adjacent.y][adjacent.x] = islandNo;

                bfsIslandPoints.push(adjacent);
            }
        }
    }
}

int main() {
    int islandNo = 0;
    queue<Point> bfsDistancePoints;
    int minBridgeDistance = 200;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j]) bfsDistancePoints.emplace(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] && !islandNoAt[i][j]) bfsIslandNo({i, j}, ++islandNo);
        }
    }

    while (!bfsDistancePoints.empty()) {
        Point current = bfsDistancePoints.front();

        bfsDistancePoints.pop();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= n) continue;

            if (!map[adjacent.y][adjacent.x]) {
                if (!islandNoAt[adjacent.y][adjacent.x]) {
                    islandNoAt[adjacent.y][adjacent.x] = islandNoAt[current.y][current.x];
                    distanceTo[adjacent.y][adjacent.x] = distanceTo[current.y][current.x] + 1;

                    bfsDistancePoints.push(adjacent);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Point current{i, j};

            for (Point difference : differences) {
                Point adjacent = current + difference;

                if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= n) continue;

                if (islandNoAt[adjacent.y][adjacent.x] != islandNoAt[current.y][current.x]) {
                    minBridgeDistance = min(minBridgeDistance,
                                            distanceTo[adjacent.y][adjacent.x] + distanceTo[current.y][current.x]);
                }
            }
        }
    }

    cout << minBridgeDistance << '\n';

    return 0;
}
