#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int value;
    bool isMerged;
} Tile;

int n;

int move(vector<vector<Tile>> board, vector<unsigned> &directions) {
    int maxValue = 0;

    for (unsigned direction : directions) {
        while (true) {
            bool areTilesMoved = false;

            switch (direction) {
                case 0: {
                    for (int j = 1; j < n; j++) {
                        for (int i = 0; i < n; i++) {
                            if (board[i][j].value == 0) continue;

                            if (board[i][j - 1].value == 0) {
                                board[i][j - 1].value = board[i][j].value;
                                board[i][j - 1].isMerged = board[i][j].isMerged;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            } else if (board[i][j - 1].value == board[i][j].value
                                       && !board[i][j - 1].isMerged && !board[i][j].isMerged) {
                                board[i][j - 1].value += board[i][j - 1].value;
                                board[i][j - 1].isMerged = true;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            }
                        }
                    }

                    break;
                }
                case 1: {
                    for (int i = n - 2; i >= 0; i--) {
                        for (int j = 0; j < n; j++) {
                            if (board[i][j].value == 0) continue;

                            if (board[i + 1][j].value == 0) {
                                board[i + 1][j].value = board[i][j].value;
                                board[i + 1][j].isMerged = board[i][j].isMerged;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            } else if (board[i + 1][j].value == board[i][j].value
                                       && !board[i + 1][j].isMerged && !board[i][j].isMerged) {
                                board[i + 1][j].value += board[i + 1][j].value;
                                board[i + 1][j].isMerged = true;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            }
                        }
                    }

                    break;
                }
                case 2: {
                    for (int i = 1; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (board[i][j].value == 0) continue;

                            if (board[i - 1][j].value == 0) {
                                board[i - 1][j].value = board[i][j].value;
                                board[i - 1][j].isMerged = board[i][j].isMerged;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            } else if (board[i - 1][j].value == board[i][j].value
                                       && !board[i - 1][j].isMerged && !board[i][j].isMerged) {
                                board[i - 1][j].value += board[i - 1][j].value;
                                board[i - 1][j].isMerged = true;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            }
                        }
                    }

                    break;
                }
                case 3: {
                    for (int j = n - 2; j >= 0; j--) {
                        for (int i = 0; i < n; i++) {
                            if (board[i][j].value == 0) continue;

                            if (board[i][j + 1].value == 0) {
                                board[i][j + 1].value = board[i][j].value;
                                board[i][j + 1].isMerged = board[i][j].isMerged;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            } else if (board[i][j + 1].value == board[i][j].value
                                       && !board[i][j + 1].isMerged && !board[i][j].isMerged) {
                                board[i][j + 1].value += board[i][j + 1].value;
                                board[i][j + 1].isMerged = true;
                                board[i][j].value = 0;
                                areTilesMoved = true;
                            }
                        }
                    }

                    break;
                }
                default: {
                    break;
                }
            }

            if (!areTilesMoved) break;
        }

        for (auto &boardRow : board) {
            for (auto &tile : boardRow) {
                tile.isMerged = false;
            }
        }
    }

    for (auto &boardRow : board) {
        for (auto &tile : boardRow) {
            maxValue = max(maxValue, tile.value);
        }
    }

    return maxValue;
}

int main() {
    int maxValue = 0;

    cin >> n;

    vector<vector<Tile>> board(n, vector<Tile>(n, {0, false}));

    for (auto &boardRow : board) {
        for (auto &tile : boardRow) {
            cin >> tile.value;
        }
    }

    for (unsigned moveBitset = 0; moveBitset < (1u << 10u); moveBitset++) {
        unsigned currentBitset = moveBitset;
        vector<unsigned> directions(5, 4);

        for (unsigned i = 0; i < 5; i++) {
            directions[i] = currentBitset & 3u;
            currentBitset >>= 2u;
        }

        maxValue = max(maxValue, move(board, directions));
    }

    cout << maxValue << '\n';

    return 0;
}
