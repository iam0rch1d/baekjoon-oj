#include <iostream>

using namespace std;

int n;
int m;
int board[20][20];
int minMoves = 11;

bool isOutOfBoard(int y, int x) {
    return y < 0 || y >= n || x < 0 || x >= m;
}

void backtrackMove(int moves, int y1, int x1, int y2, int x2) {
    if (moves >= 11 || (isOutOfBoard(y1, x1) && isOutOfBoard(y2, x2))) return;

    if (isOutOfBoard(y1, x1) ^ isOutOfBoard(y2, x2)) {
        minMoves = min(minMoves, moves);

        return;
    }

    for (int i = 0; i < 4; i++) {
        int dy = "1201"[i] - '1';
        int dx = "0112"[i] - '1';
        int ny1 = y1 + dy;
        int nx1 = x1 + dx;
        int ny2 = y2 + dy;
        int nx2 = x2 + dx;

        if (!isOutOfBoard(ny1, nx1) && board[ny1][nx1]) {
            ny1 = y1;
            nx1 = x1;
        }

        if (!isOutOfBoard(ny2, nx2) && board[ny2][nx2]) {
            ny2 = y2;
            nx2 = x2;
        }

        backtrackMove(moves + 1, ny1, nx1, ny2, nx2);
    }
}

int main() {
    int y1 = -1;
    int x1;
    int y2;
    int x2;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string boardRow;

        cin >> boardRow;

        for (int j = 0; j < m; j++) {
            if (boardRow[j] == 'o') {
                if (y1 == -1) {
                    y1 = i;
                    x1 = j;
                } else {
                    y2 = i;
                    x2 = j;
                }
            }

            board[i][j] = boardRow[j] == '#';
        }
    }

    backtrackMove(0, y1, x1, y2, x2);

    cout << (minMoves == 11 ? -1 : minMoves) << '\n';

    return 0;
}
