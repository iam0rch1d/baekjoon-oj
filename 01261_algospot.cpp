#include <cstring>
#include <deque>
#include <iostream>

#define MAX_SIZE 100

using namespace std;

typedef struct Point {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int breakCountAt[MAX_SIZE][MAX_SIZE];

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

    breakCountAt[0][0] = 1;

    bfsPoints.push_front({0, 0});

    while (!bfsPoints.empty()) {
        Point current = bfsPoints.front();

        if (current.y == n - 1 && current.x == m - 1) {
            cout << breakCountAt[current.y][current.x] - 1 << '\n';

            return 0;
        }

        bfsPoints.pop_front();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0
                || adjacent.y >= n
                || adjacent.x < 0
                || adjacent.x >= m
                || breakCountAt[adjacent.y][adjacent.x]) {
                continue;
            }

            breakCountAt[adjacent.y][adjacent.x] = breakCountAt[current.y][current.x] + map[adjacent.y][adjacent.x];

            map[adjacent.y][adjacent.x] ? bfsPoints.push_back(adjacent) : bfsPoints.push_front(adjacent);
        }
    }
}
