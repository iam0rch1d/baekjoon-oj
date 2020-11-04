#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

#define MAX_SIZE 1000

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int movesAt[MAX_SIZE][MAX_SIZE][11][2];

int main() {
    int n;
    int m;
    int k;
    queue<tuple<int, int, int, int>> bfsPoints;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    movesAt[0][0][0][0] = 1;

    bfsPoints.push({0, 0, 0, 0});

    while (!bfsPoints.empty()) {
        int y;
        int x;
        int brokenWalls;
        int isNight;

        tie(y, x, brokenWalls, isNight) = bfsPoints.front();

        if (y == n - 1 && x == m - 1) {
            vector<int> possibleMoves;

            for (int i = 0; i <= k; i++) {
                if (movesAt[y][x][i][0]) possibleMoves.push_back(movesAt[y][x][i][0]);

                if (movesAt[y][x][i][1]) possibleMoves.push_back(movesAt[y][x][i][1]);
            }

            cout << *min_element(possibleMoves.begin(), possibleMoves.end()) << '\n';

            return 0;
        }

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!map[ny][nx] && !movesAt[ny][nx][brokenWalls][1 - isNight]) {
                movesAt[ny][nx][brokenWalls][1 - isNight] = movesAt[y][x][brokenWalls][isNight] + 1;

                bfsPoints.push({ny, nx, brokenWalls, 1 - isNight});
            }

            if (map[ny][nx] && !movesAt[ny][nx][brokenWalls + 1][1 - isNight] && brokenWalls < k && !isNight) {
                movesAt[ny][nx][brokenWalls + 1][1] = movesAt[y][x][brokenWalls][isNight] + 1;

                bfsPoints.push({ny, nx, brokenWalls + 1, 1});
            }
        }

        if (!movesAt[y][x][brokenWalls][1 - isNight]) {
            movesAt[y][x][brokenWalls][1 - isNight] = movesAt[y][x][brokenWalls][isNight] + 1;

            bfsPoints.push({y, x, brokenWalls, 1 - isNight});
        }
    }

    cout << "-1\n";

    return 0;
}
