#include <iostream>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

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

void backtrackSudoku(int numberNo) {
    if (numberNo == 81) {
        for (auto &numberRow : numberTable) {
            for (int i = 0; i < 9; i++) {
                cout << numberRow[i] << " \n"[i == 8];
            }
        }

        exit(0);
    }

    int y = numberNo / 9;
    int x = numberNo % 9;

    if (numberTable[y][x]) backtrackSudoku(numberNo + 1);
    else {
        for (int i = 1; i <= 9; i++) {
            if (canCheck(i, {y, x})) {
                check(i, {y, x}, true);
                backtrackSudoku(numberNo + 1);
                check(i, {y, x}, false);
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int number;

            cin >> number;

            check(number, {i, j}, true);
        }
    }

    backtrackSudoku(0);
}
