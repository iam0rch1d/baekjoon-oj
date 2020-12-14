#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_SIZE 200

int map[MAX_SIZE][MAX_SIZE];
int movesAt[MAX_SIZE][MAX_SIZE][31];

int main() {
    int k;
    int w;
    int h;
    queue<tuple<int, int, int>> bfsPoints;

    cin >> k >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    movesAt[0][0][0] = 1;

    bfsPoints.push({0, 0, 0});

    while (!bfsPoints.empty()) {
        int y;
        int x;
        int knightMoves;

        tie(y, x, knightMoves) = bfsPoints.front();

        if (y == h - 1 && x == w - 1) {
            cout << movesAt[y][x][knightMoves] - 1 << '\n';

            return 0;
        }

        bfsPoints.pop();

        for (int i = 0; i < (knightMoves < k ? 12 : 4); i++) {
            int ny = y + "231200113344"[i] - '2';
            int nx = x + "122313040413"[i] - '2';

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

            if (!map[ny][nx] && !movesAt[ny][nx][knightMoves + (i >= 4)]) {
                movesAt[ny][nx][knightMoves + (i >= 4)] = movesAt[y][x][knightMoves] + 1;

                bfsPoints.push({ny, nx, knightMoves + (i >= 4)});
            }
        }
    }

    cout << "-1\n";

    return 0;
}
