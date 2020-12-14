#include <deque>
#include <iostream>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

#define MAX_SIZE 100

int brokenWallsAt[MAX_SIZE][MAX_SIZE];

int main() {
    int n;
    int m;
    int map[MAX_SIZE][MAX_SIZE];
    deque<Point> bfsPoints;
    const Point differences[] = {{0,  -1},
                                 {1,  0},
                                 {-1, 0},
                                 {0,  1}};

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    brokenWallsAt[0][0] = 1;

    bfsPoints.push_front({0, 0});

    while (!bfsPoints.empty()) {
        Point current = bfsPoints.front();

        if (current.y == n - 1 && current.x == m - 1) {
            cout << brokenWallsAt[current.y][current.x] - 1 << '\n';

            return 0;
        }

        bfsPoints.pop_front();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0
                || adjacent.y >= n
                || adjacent.x < 0
                || adjacent.x >= m
                || brokenWallsAt[adjacent.y][adjacent.x]) {
                continue;
            }

            brokenWallsAt[adjacent.y][adjacent.x] = brokenWallsAt[current.y][current.x] + map[adjacent.y][adjacent.x];

            map[adjacent.y][adjacent.x] ? bfsPoints.push_back(adjacent) : bfsPoints.push_front(adjacent);
        }
    }
}
