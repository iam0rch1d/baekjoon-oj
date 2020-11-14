#include <cstring>
#include <iostream>
#include <queue>

#define MAX_SIZE 50

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
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

void bfsLandNo(Point point, int landNo) {
    queue<Point> bfsPoints;

    landNoAt[point.y][point.x] = landNo;

    bfsPoints.push(point);

    while (!bfsPoints.empty()) {
        point = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacent = point + difference;

            if (adjacent.y < 0 || adjacent.y >= h || adjacent.x < 0 || adjacent.x >= w) continue;

            if (map[adjacent.y][adjacent.x] && !landNoAt[adjacent.y][adjacent.x]) {
                landNoAt[adjacent.y][adjacent.x] = landNo;

                bfsPoints.push(adjacent);
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
                if (map[i][j] && !landNoAt[i][j]) bfsLandNo({i, j}, ++landCount);
            }
        }

        cout << landCount << '\n';

        memset(map, 0, sizeof(map));
        memset(landNoAt, 0, sizeof(landNoAt));
    }
}
