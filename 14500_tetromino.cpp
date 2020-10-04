#include <iostream>
#include <vector>

using namespace std;

int main() {
    int boardRowSize;
    int boardHeightSize;
    int maxScore = -1;

    cin >> boardRowSize >> boardHeightSize;

    vector<vector<int>> board(boardRowSize, vector<int>(boardHeightSize));

    for (auto &boardRow : board) {
        for (int &boardElement : boardRow) {
            cin >> boardElement;
        }
    }

    // tetrominoes[tetrominoNo][tetrominoRow][tetrominoColumn]
    const vector<vector<vector<int>>> tetrominoes = {{{1, 1, 1}, {0, 1, 0}},
                                                     {{1, 0},    {1, 1}, {1, 0}},
                                                     {{0, 1, 0}, {1, 1, 1}},
                                                     {{0, 1},    {1, 1}, {0, 1}},
                                                     {{1, 1, 1}, {0, 0, 1}},
                                                     {{1, 1},    {1, 0}, {1, 0}},
                                                     {{1, 0, 0}, {1, 1, 1}},
                                                     {{0, 1},    {0, 1}, {1, 1}},
                                                     {{1, 1, 1}, {1, 0, 0}},
                                                     {{1, 0},    {1, 0}, {1, 1}},
                                                     {{0, 0, 1}, {1, 1, 1}},
                                                     {{1, 1},    {0, 1}, {0, 1}},
                                                     {{1, 1, 0}, {0, 1, 1}},
                                                     {{1, 0},    {1, 1}, {0, 1}},
                                                     {{0, 1, 1}, {1, 1, 0}},
                                                     {{0, 1},    {1, 1}, {1, 0}},
                                                     {{1, 1, 1, 1}},
                                                     {{1},       {1},    {1}, {1}},
                                                     {{1, 1},    {1, 1}}};

    for (auto tetromino : tetrominoes) {
        for (int row = 0; row + tetromino.size() <= boardRowSize; row++) {
            for (int column = 0; column + tetromino[0].size() <= boardHeightSize; column++) {
                int score = 0;

                for (int i = 0; i < tetromino.size(); i++) {
                    for (int j = 0; j < tetromino[0].size(); j++) {
                        score += tetromino[i][j] * board[row + i][column + j];
                    }
                }

                maxScore = max(maxScore, score);
            }
        }
    }

    cout << maxScore << '\n';

    return 0;
}
