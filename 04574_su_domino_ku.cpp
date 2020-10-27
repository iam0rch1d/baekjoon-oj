#include <cstring>
#include <iostream>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

bool isFull;
int numberTable[9][9];
bool isNumberInRow[9][10];
bool isNumberInColumn[9][10];
bool isNumberInBox[9][10];
bool isDominoUsed[10][10];

int boxOf(Point point) {
    return point.y / 3 * 3 + point.x / 3;
}

bool canCheck(int number, Point at) {
    return !isNumberInRow[at.y][number] && !isNumberInColumn[at.x][number] && !isNumberInBox[boxOf(at)][number];
}

void check(int number, Point at, bool what) {
    numberTable[at.y][at.x] = what ? number : 0;
    isNumberInRow[at.y][number] = what;
    isNumberInColumn[at.x][number] = what;
    isNumberInBox[boxOf(at)][number] = what;
}

void backtrackSudominoku(int numberNo) {
    if (!isFull && numberNo == 81) {
        isFull = true;

        for (auto &numberRow : numberTable) {
            for (int number : numberRow) {
                cout << number;
            }

            cout << '\n';
        }

        return;
    }

    int y = numberNo / 9;
    int x = numberNo % 9;

    if (numberTable[y][x]) backtrackSudominoku(numberNo + 1);
    else {
        for (int i = 0; i < 2; i++) {
            int ny = y + "01"[i] - '0';
            int nx = x + "10"[i] - '0';

            if (ny < 0 || ny >= 9 || nx < 0 || nx >= 9 || numberTable[ny][nx]) continue;

            for (int j = 1; j <= 9; j++) {
                for (int k = 1; k <= 9; k++) {
                    if (j != k && !isDominoUsed[j][k] && canCheck(j, {y, x}) && canCheck(k, {ny, nx})) {
                        isDominoUsed[j][k] = true;
                        isDominoUsed[k][j] = true;

                        check(j, {y, x}, true);
                        check(k, {ny, nx}, true);
                        backtrackSudominoku(numberNo + 1);

                        isDominoUsed[j][k] = false;
                        isDominoUsed[k][j] = false;

                        check(j, {y, x}, false);
                        check(k, {ny, nx}, false);
                    }
                }
            }
        }
    }
}

int main() {
    int testcaseNo = 0;

    while (true) {
        int n;

        cin >> n;

        if (n == 0) return 0;

        for (int i = 0; i < n; i++) {
            int u;
            string lu;
            int v;
            string lv;

            cin >> u >> lu >> v >> lv;

            check(u, {lu[0] - 'A', lu[1] - '1'}, true);
            check(v, {lv[0] - 'A', lv[1] - '1'}, true);

            isDominoUsed[u][v] = true;
            isDominoUsed[v][u] = true;
        }

        for (int i = 1; i <= 9; i++) {
            string code;

            cin >> code;

            check(i, {code[0] - 'A', code[1] - '1'}, true);
        }

        cout << "Puzzle " << ++testcaseNo << '\n';

        backtrackSudominoku(0);

        isFull = false;

        memset(numberTable, 0, sizeof(numberTable));
        memset(isNumberInRow, 0, sizeof(isNumberInRow));
        memset(isNumberInColumn, 0, sizeof(isNumberInColumn));
        memset(isNumberInBox, 0, sizeof(isNumberInBox));
        memset(isDominoUsed, 0, sizeof(isDominoUsed));
    }
}
