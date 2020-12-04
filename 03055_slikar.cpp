#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int floodingTimeAt[50][50];
int movingTimeAt[50][50];

int main() {
    int r;
    int c;
    int dy;
    int dx;
    queue<pair<int, int>> bfsFloodingPoints;
    queue<pair<int, int>> bfsMovingPoints;

    memset(floodingTimeAt, -1, sizeof(floodingTimeAt));
    memset(movingTimeAt, -1, sizeof(movingTimeAt));

    cin >> r >> c;

    vector<string> map(r);

    for (int i = 0; i < r; i++) {
        cin >> map[i];

        for (int j = 0; j < c; j++) {
            if (map[i][j] == '*') {
                floodingTimeAt[i][j] = 0;

                bfsFloodingPoints.push({i, j});
            } else if (map[i][j] == 'S') {
                movingTimeAt[i][j] = 0;

                bfsMovingPoints.push({i, j});
            } else if (map[i][j] == 'D') tie(dy, dx) = {i, j};
        }
    }

    while (!bfsFloodingPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsFloodingPoints.front();

        bfsFloodingPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= r || nx < 0 || nx >= c
                || floodingTimeAt[ny][nx] != -1 || map[ny][nx] == 'X' || map[ny][nx] == 'D') {
                continue;
            }

            floodingTimeAt[ny][nx] = floodingTimeAt[y][x] + 1;

            bfsFloodingPoints.push({ny, nx});
        }
    }

    while (!bfsMovingPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsMovingPoints.front();

        if (y == dy && x == dx) {
            cout << movingTimeAt[dy][dx] << '\n';

            return 0;
        }

        bfsMovingPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= r || nx < 0 || nx >= c
                || (floodingTimeAt[ny][nx] != - 1 && floodingTimeAt[ny][nx] <= movingTimeAt[y][x] + 1)
                || movingTimeAt[ny][nx] != -1
                || map[ny][nx] == 'X') {
                continue;
            }

            movingTimeAt[ny][nx] = movingTimeAt[y][x] + 1;

            bfsMovingPoints.push({ny, nx});
        }
    }

    cout << "KAKTUS\n";

    return 0;
}
