#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

class Sudoku {
public:
    int numberTable[9][9]{};
    bool isNumberInRow[9][10]{};
    bool isNumberInColumn[9][10]{};
    bool isNumberInBox[9][10]{};
    vector<Point> blanks;
    vector<bool> isBlankFilled;

    explicit Sudoku(int numberTable[9][9]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j <= 9; j++) {
                isNumberInRow[i][j] = false;
                isNumberInColumn[i][j] = false;
                isNumberInBox[i][j] = false;
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (numberTable[i][j] != 0) {
                    this->numberTable[i][j] = numberTable[i][j];
                    isNumberInRow[i][numberTable[i][j]] = true;
                    isNumberInColumn[j][numberTable[i][j]] = true;
                    isNumberInBox[(i / 3) * 3 + j / 3][numberTable[i][j]] = true;
                } else {
                    blanks.push_back({i, j});
                    isBlankFilled.push_back(false);
                }
            }
        }
    }
};

void backtrackNumber(Sudoku sudoku) {
    int indexBlankToFill = -1;
    Point toFill;

    for (int i = 0; i < sudoku.blanks.size(); i++) {
        if (!sudoku.isBlankFilled[i]) {
            indexBlankToFill = i;
            toFill = sudoku.blanks[i];

            break;
        }
    }

    if (indexBlankToFill == -1) {
        for (const auto &numberRow : sudoku.numberTable) {
            for (int number : numberRow) {
                cout << number << " ";
            }

            cout << endl;
        }

        exit(0);
    }

    for (int candidate = 1; candidate <= 9; candidate++) {
        if (!sudoku.isNumberInRow[toFill.y][candidate]
            && !sudoku.isNumberInColumn[toFill.x][candidate]
            && !sudoku.isNumberInBox[(toFill.y / 3) * 3 + toFill.x / 3][candidate]
                ) {
            sudoku.numberTable[toFill.y][toFill.x] = candidate;
            sudoku.isNumberInRow[toFill.y][candidate] = true;
            sudoku.isNumberInColumn[toFill.x][candidate] = true;
            sudoku.isNumberInBox[(toFill.y / 3) * 3 + toFill.x / 3][candidate] = true;
            sudoku.isBlankFilled[indexBlankToFill] = true;

            backtrackNumber(sudoku);

            sudoku.numberTable[toFill.y][toFill.x] = 0;
            sudoku.isNumberInRow[toFill.y][candidate] = false;
            sudoku.isNumberInColumn[toFill.x][candidate] = false;
            sudoku.isNumberInBox[(toFill.y / 3) * 3 + toFill.x / 3][candidate] = false;
            sudoku.isBlankFilled[indexBlankToFill] = false;
        }
    }
}

int main() {
    int numberTable[9][9];

    for (auto &numberRow : numberTable) {
        for (int &number : numberRow) {
            cin >> number;
        }
    }

    backtrackNumber(Sudoku(numberTable));

    return 0;
}
