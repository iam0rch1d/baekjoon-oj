#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 300

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int movesAt[MAX_SIZE][MAX_SIZE];

int main() {
    int tc;
    const Point differences[] = {{-2, -1},
                                 {-2, 1},
                                 {-1, -2},
                                 {-1, 2},
                                 {1,  -2},
                                 {1,  2},
                                 {2,  -1},
                                 {2,  1}};

    cin >> tc;

    while (tc--) {
        int n;
        Point initial;
        Point target;
        queue<Point> bfsPoints;

        cin >> n >> initial.y >> initial.x >> target.y >> target.x;

        movesAt[initial.y][initial.x] = 1;

        bfsPoints.emplace(initial.y, initial.x);

        while (!bfsPoints.empty()) {
            Point current = bfsPoints.front();

            bfsPoints.pop();

            for (Point difference : differences) {
                Point adjacent = current + difference;

                if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= n) continue;

                if (!movesAt[adjacent.y][adjacent.x]) {
                    movesAt[adjacent.y][adjacent.x] = movesAt[current.y][current.x] + 1;

                    bfsPoints.push(adjacent);
                }
            }
        }

        cout << movesAt[target.y][target.x] - 1 << '\n';

        memset(movesAt, 0, sizeof(movesAt));
    }

    return 0;
}
