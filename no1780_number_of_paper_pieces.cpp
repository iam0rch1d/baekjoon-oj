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
                    int &numMinusOnePiece,
                    int &numZeroPiece,
                    int &numPlusOnePiece) {
    int numMinusOnePoint = 0;
    int numPlusOnePoint = 0;

    for (int i = start.y; i < start.y + size; i++) {
        for (int j = start.x; j < start.x + size; j++) {
            numMinusOnePoint += (colors[i][j] == -1) ? 1 : 0;
            numPlusOnePoint += (colors[i][j] == 1) ? 1 : 0;
        }
    }

    if (numMinusOnePoint == size * size) numMinusOnePiece++;
    else if (numMinusOnePoint == 0 && numPlusOnePoint == 0) numZeroPiece++;
    else if (numPlusOnePoint == size * size) numPlusOnePiece++;
    else {
        dncNumberPiece(colors,
                       start,
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y, start.x + size / 3},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y, start.x + size / 3 * 2},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y + size / 3, start.x},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y + size / 3, start.x + size / 3},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y + size / 3, start.x + size / 3 * 2},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y + size / 3 * 2, start.x},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y + size / 3 * 2, start.x + size / 3},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
        dncNumberPiece(colors,
                       {start.y + size / 3 * 2, start.x + size / 3 * 2},
                       size / 3,
                       numMinusOnePiece,
                       numZeroPiece,
                       numPlusOnePiece);
    }
}

int main() {
    int size;
    int numMinusOnePiece = 0;
    int numZeroPiece = 0;
    int numPlusOnePiece = 0;

    cin >> size;

    vector<vector<int>> colors(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> colors[i][j];
        }
    }

    dncNumberPiece(colors, {0, 0}, size, numMinusOnePiece, numZeroPiece, numPlusOnePiece);

    cout << numMinusOnePiece << endl << numZeroPiece << endl << numPlusOnePiece;

    return 0;
}
