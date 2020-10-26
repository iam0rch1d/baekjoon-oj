#include <cstring>
#include <iostream>
#include <queue>

#define MAX_SIZE 300

using namespace std;

typedef struct Point {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int moveCountAt[MAX_SIZE][MAX_SIZE];

int main() {
    int numTestcase;
    const Point differences[] = {{-2, -1},
                                 {-2, 1},
                                 {-1, -2},
                                 {-1, 2},
                                 {1,  -2},
                                 {1,  2},
                                 {2,  -1},
                                 {2,  1}};

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int n;
        Point initial;
        Point target;
        queue<Point> bfsPoints;

        cin >> n >> initial.y >> initial.x >> target.y >> target.x;

        moveCountAt[initial.y][initial.x] = 1;

        bfsPoints.push({initial.y, initial.x});

        while (!bfsPoints.empty()) {
            Point current = bfsPoints.front();

            bfsPoints.pop();

            for (Point difference : differences) {
                Point adjacent = current + difference;

                if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= n) continue;

                if (!moveCountAt[adjacent.y][adjacent.x]) {
                    moveCountAt[adjacent.y][adjacent.x] = moveCountAt[current.y][current.x] + 1;

                    bfsPoints.push(adjacent);
                }
            }
        }

        cout << moveCountAt[target.y][target.x] - 1 << '\n';

        memset(moveCountAt, 0, sizeof(moveCountAt));
    }

    return 0;
}