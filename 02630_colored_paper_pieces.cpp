#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

void dncColoredPiece(vector<vector<int>> &colors, Point start, int size, int &whitePieceCount, int &bluePieceCount) {
    int bluePointCount = 0;

    for (int i = start.y; i < start.y + size; i++) {
        for (int j = start.x; j < start.x + size; j++) {
            bluePointCount += colors[i][j];
        }
    }

    if (bluePointCount == 0) whitePieceCount++;
    else if (bluePointCount == size * size) bluePieceCount++;
    else {
        dncColoredPiece(colors, start, size / 2, whitePieceCount, bluePieceCount);
        dncColoredPiece(colors, {start.y, start.x + size / 2}, size / 2, whitePieceCount, bluePieceCount);
        dncColoredPiece(colors, {start.y + size / 2, start.x}, size / 2, whitePieceCount, bluePieceCount);
        dncColoredPiece(colors, {start.y + size / 2, start.x + size / 2}, size / 2, whitePieceCount, bluePieceCount);
    }
}

int main() {
    int size;
    int whitePieceCount = 0;
    int bluePieceCount = 0;

    cin >> size;

    vector<vector<int>> colors(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> colors[i][j];
        }
    }

    dncColoredPiece(colors, {0, 0}, size, whitePieceCount, bluePieceCount);

    cout << whitePieceCount << endl << bluePieceCount << endl;

    return 0;
}
