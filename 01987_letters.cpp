#include <iostream>

using namespace std;

int r;
int c;
char board[20][20];
bool isVisited[26];
int maxMoves;

void backtrackMove(int moves, int y, int x) {
    if (moves >= 26) {
        cout << "26\n";

        exit(0);
    }

    maxMoves = max(maxMoves, moves);

    for (int i = 0; i < 4; i++) {
        int ny = y + "1201"[i] - '1';
        int nx = x + "0112"[i] - '1';

        if (ny >= 0 && ny < r && nx >= 0 && nx < c && !isVisited[board[ny][nx] - 'A']) {
            isVisited[board[ny][nx] - 'A'] = true;

            backtrackMove(moves + 1, ny, nx);

            isVisited[board[ny][nx] - 'A'] = false;
        }
    }
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string boardRow;

        cin >> boardRow;

        for (int j = 0; j < c; j++) {
            board[i][j] = boardRow[j];
        }
    }

    isVisited[board[0][0] - 'A'] = true;

    backtrackMove(1, 0, 0);

    cout << maxMoves << '\n';

    return 0;
}
