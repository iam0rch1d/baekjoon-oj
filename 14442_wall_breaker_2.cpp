#include <iostream>
#include <queue>
#include <tuple>

#define MAX_SIZE 1000

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int movesAt[MAX_SIZE][MAX_SIZE][11];

int main() {
    int n;
    int m;
    int k;
    queue<tuple<int, int, int>> bfsPoints;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    movesAt[0][0][0] = 1;

    bfsPoints.push({0, 0, 0});

    while (!bfsPoints.empty()) {
        int y;
        int x;
        int brokenWalls;

        tie(y, x, brokenWalls) = bfsPoints.front();

        if (y == n - 1 && x == m - 1) {
            cout << movesAt[y][x][brokenWalls] << '\n';

            return 0;
        }

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!map[ny][nx] && !movesAt[ny][nx][brokenWalls]) {
                movesAt[ny][nx][brokenWalls] = movesAt[y][x][brokenWalls] + 1;

                bfsPoints.push({ny, nx, brokenWalls});
            }

            if (map[ny][nx] && !movesAt[ny][nx][brokenWalls + 1] && brokenWalls < k) {
                movesAt[ny][nx][brokenWalls + 1] = movesAt[y][x][brokenWalls] + 1;

                bfsPoints.push({ny, nx, brokenWalls + 1});
            }
        }
    }

    cout << "-1\n";

    return 0;
}
