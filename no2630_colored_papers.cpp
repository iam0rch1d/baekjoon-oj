#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

void compressToQuadtree(vector<vector<int>> &colors, Point start, int size, int &numWhitePiece, int &numBluePiece) {
    int numBluePoint = 0;

    for (int i = start.y; i < start.y + size; i++) {
        for (int j = start.x; j < start.x + size; j++) {
            numBluePoint += colors[i][j];
        }
    }

    if (numBluePoint == 0) numWhitePiece++;
    else if (numBluePoint == size * size) numBluePiece++;
    else {
        compressToQuadtree(colors, start, size / 2, numWhitePiece, numBluePiece);
        compressToQuadtree(colors, {start.y, start.x + size / 2}, size / 2, numWhitePiece, numBluePiece);
        compressToQuadtree(colors, {start.y + size / 2, start.x}, size / 2, numWhitePiece, numBluePiece);
        compressToQuadtree(colors, {start.y + size / 2, start.x + size / 2}, size / 2, numWhitePiece, numBluePiece);
    }
}

int main() {
    int size;
    int numWhitePiece = 0;
    int numBluePiece = 0;

    cin >> size;

    vector<vector<int>> colors(size, vector<int> (size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> colors[i][j];
        }
    }

    compressToQuadtree(colors, {0, 0}, size, numWhitePiece, numBluePiece);

    cout << numWhitePiece << endl << numBluePiece << endl;

    return 0;
}
