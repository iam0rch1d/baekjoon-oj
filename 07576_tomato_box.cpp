#include <iostream>
#include <queue>

#define MAX_SIZE 1000

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int map[MAX_SIZE][MAX_SIZE];

int main() {
    int n;
    int m;
    queue<Point> bfsPoints;
    const Point differences[] = {{0,  -1},
                                 {1,  0},
                                 {-1, 0},
                                 {0,  1}};
    int maxDays = 0;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1) bfsPoints.push({i, j});
        }
    }

    while (!bfsPoints.empty()) {
        Point current = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= m) continue;

            if (!map[adjacent.y][adjacent.x]) {
                map[adjacent.y][adjacent.x] = map[current.y][current.x] + 1;

                bfsPoints.push(adjacent);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j]) {
                cout << "-1\n";

                return 0;
            }

            maxDays = max(maxDays, map[i][j]);
        }
    }

    cout << maxDays - 1 << '\n';

    return 0;
}
