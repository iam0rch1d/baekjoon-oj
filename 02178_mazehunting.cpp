#include <iostream>
#include <queue>

#define MAX_SIZE 100

using namespace std;

typedef struct Point {
    int y;
    int x;
} Point;

Point operator+(Point point1, Point point2) {
    return {point1.y + point2.y, point1.x + point2.x};
}

int moveCountAt[MAX_SIZE][MAX_SIZE];

int main() {
    int n;
    int m;
    int map[MAX_SIZE][MAX_SIZE];
    queue<Point> bfsPoints;
    const Point differences[] = {{0,  -1},
                                 {1,  0},
                                 {-1, 0},
                                 {0,  1}};

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    moveCountAt[0][0] = 1;

    bfsPoints.push({0, 0});

    while (!bfsPoints.empty()) {
        Point current = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= m) continue;

            if (map[adjacent.y][adjacent.x] && !moveCountAt[adjacent.y][adjacent.x]) {
                moveCountAt[adjacent.y][adjacent.x] = moveCountAt[current.y][current.x] + 1;

                bfsPoints.push(adjacent);
            }
        }
    }

    cout << moveCountAt[n - 1][m - 1] << '\n';

    return 0;
}
