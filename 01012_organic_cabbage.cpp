#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 50

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int n;
int m;
int map[MAX_SIZE][MAX_SIZE];
int cabbageChunkNoAt[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{0,  -1},
                             {1,  0},
                             {-1, 0},
                             {0,  1}};

void bfsCabbageChunkNo(Point current, int cabbageChunkNo) {
    queue<Point> bfsPoints;

    cabbageChunkNoAt[current.y][current.x] = cabbageChunkNo;

    bfsPoints.push(current);

    while (!bfsPoints.empty()) {
        current = bfsPoints.front();

        bfsPoints.pop();

        for (Point difference : differences) {
            Point adjacent = current + difference;

            if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= m) continue;

            if (map[adjacent.y][adjacent.x] && !cabbageChunkNoAt[adjacent.y][adjacent.x]) {
                cabbageChunkNoAt[adjacent.y][adjacent.x] = cabbageChunkNo;

                bfsPoints.push(adjacent);
            }
        }
    }
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int numCabbage;
        int cabbageChunkCount = 0;

        cin >> m >> n >> numCabbage;

        while (numCabbage-- > 0) {
            int y;
            int x;

            cin >> x >> y;

            map[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] && !cabbageChunkNoAt[i][j]) bfsCabbageChunkNo({i, j}, ++cabbageChunkCount);
            }
        }

        cout << cabbageChunkCount << '\n';

        memset(map, 0, sizeof(map));
        memset(cabbageChunkNoAt, 0, sizeof(cabbageChunkNoAt));
    }

    return 0;
}
