#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_SIZE 1000

int map[MAX_SIZE][MAX_SIZE];
int movesAt[MAX_SIZE][MAX_SIZE][2];

int main() {
    int n;
    int m;
    queue<tuple<int, int, int>> bfsPoints;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    movesAt[0][0][0] = 1;

    bfsPoints.emplace(0, 0, 0);

    while (!bfsPoints.empty()) {
        int y;
        int x;
        int brokenWalls;

        tie(y, x, brokenWalls) = bfsPoints.front();

        if (y == n - 1 && x == m - 1) {
            vector<int> possibleMoves;

            for (int i = 0; i <= 1; i++) {
                if (movesAt[y][x][i]) possibleMoves.push_back(movesAt[y][x][i]);
            }

            cout << *min_element(possibleMoves.begin(), possibleMoves.end()) << '\n';

            return 0;
        }

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!map[ny][nx] && !movesAt[ny][nx][brokenWalls]) {
                movesAt[ny][nx][brokenWalls] = movesAt[y][x][brokenWalls] + 1;

                bfsPoints.emplace(ny, nx, brokenWalls);
            }

            if (map[ny][nx] && !movesAt[ny][nx][brokenWalls + 1] && brokenWalls < 1) {
                movesAt[ny][nx][brokenWalls + 1] = movesAt[y][x][brokenWalls] + 1;

                bfsPoints.emplace(ny, nx, brokenWalls + 1);
            }
        }
    }

    cout << "-1\n";

    return 0;
}
