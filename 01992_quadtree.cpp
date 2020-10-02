#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

string dncQuadtree(vector<vector<int>> &colors, Point start, int size) {
    int numBlackPoint = 0;

    for (int i = start.y; i < start.y + size; i++) {
        for (int j = start.x; j < start.x + size; j++) {
            numBlackPoint += colors[i][j];
        }
    }

    if (numBlackPoint == 0) return "0";
    else if (numBlackPoint == size * size) return "1";
    else {
        return "("
        + dncQuadtree(colors, start, size / 2)
        + dncQuadtree(colors, {start.y, start.x + size / 2}, size / 2)
        + dncQuadtree(colors, {start.y + size / 2, start.x}, size / 2)
        + dncQuadtree(colors, {start.y + size / 2, start.x + size / 2}, size / 2)
        + ")";
    }
}

int main() {
    int size;

    cin >> size;

    vector<string> colorsString(size);
    vector<vector<int>> colors(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        cin >> colorsString[i];

        for (int j = 0; j < size; j++) {
            colors[i][j] = colorsString[i].at(j) - '0';
        }
    }

    cout << dncQuadtree(colors, {0, 0}, size) << '\n';

    return 0;
}
