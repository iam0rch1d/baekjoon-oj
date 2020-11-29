#include <cstring>
#include <iostream>

#define INF 1000001

using namespace std;

int minMoveCount = INF;
int n;
int m;
string board[30];
int dy[4] = {0, 1, -1, 0};
int dx[4] = {-1, 0, 0, 1};

void backtrackMove(int unvisitedCount, int moveCount, int y, int x) {
    if (!unvisitedCount) {
        minMoveCount = min(minMoveCount, moveCount);

        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        while (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] == '.') {
            board[ny][nx] = '*';
            unvisitedCount--;
            ny += dy[i];
            nx += dx[i];
        }

        ny -= dy[i];
        nx -= dx[i];

        if (!(nx == x && ny == y)) {
            backtrackMove(unvisitedCount, moveCount + 1, ny, nx);
        }

        while (!(nx == x && ny == y)) {
            board[ny][nx] = '.';
            unvisitedCount++;
            ny -= dy[i];
            nx -= dx[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases = 0;

    while (cin >> n >> m) {
        int unvisitedCount = 0;

        for (int i = 0; i < n; i++) {
            cin >> board[i];

            for (int j = 0; j < m; j++) {
                unvisitedCount += board[i][j] == '.';
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '*') continue;

                board[i][j] = '*';

                backtrackMove(unvisitedCount - 1, 0, i, j);

                board[i][j] = '.';
            }
        }

        cout << "Case " << ++testcases << ": " << (minMoveCount == INF ? -1 : minMoveCount) << '\n';

        minMoveCount = INF;
    }

    return 0;
}
