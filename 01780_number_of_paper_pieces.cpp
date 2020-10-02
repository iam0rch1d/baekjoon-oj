#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

void dncNumberPiece(vector<vector<int>> &colors,
                    Point start,
                    int size,
                    int &minusOnePieceCount,
                    int &zeroPieceCount,
                    int &plusOnePieceCount) {
    int minusOnePointCount = 0;
    int plusOnePointCount = 0;

    for (int i = start.y; i < start.y + size; i++) {
        for (int j = start.x; j < start.x + size; j++) {
            minusOnePointCount += (colors[i][j] == -1) ? 1 : 0;
            plusOnePointCount += (colors[i][j] == 1) ? 1 : 0;
        }
    }

    if (minusOnePointCount == size * size) minusOnePieceCount++;
    else if (minusOnePointCount == 0 && plusOnePointCount == 0) zeroPieceCount++;
    else if (plusOnePointCount == size * size) plusOnePieceCount++;
    else {
        dncNumberPiece(colors,
                       start,
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y, start.x + size / 3},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y, start.x + size / 3 * 2},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y + size / 3, start.x},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y + size / 3, start.x + size / 3},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y + size / 3, start.x + size / 3 * 2},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y + size / 3 * 2, start.x},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y + size / 3 * 2, start.x + size / 3},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
        dncNumberPiece(colors,
                       {start.y + size / 3 * 2, start.x + size / 3 * 2},
                       size / 3,
                       minusOnePieceCount,
                       zeroPieceCount,
                       plusOnePieceCount);
    }
}

int main() {
    int size;
    int minusOnePieceCount = 0;
    int zeroPieceCount = 0;
    int plusOnePieceCount = 0;

    cin >> size;

    vector<vector<int>> colors(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> colors[i][j];
        }
    }

    dncNumberPiece(colors, {0, 0}, size, minusOnePieceCount, zeroPieceCount, plusOnePieceCount);

    cout << minusOnePieceCount << '\n' << zeroPieceCount << '\n' << plusOnePieceCount;

    return 0;
}
