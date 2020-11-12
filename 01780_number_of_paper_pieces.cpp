#include <iostream>

using namespace std;

int colors[2187][2187];
int pieceCounts[3];

void dncPiece(int y, int x, int size) {
    bool isAllSame = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (colors[i][j] != colors[y][x]) {
                isAllSame = false;

                break;
            }
        }

        if (!isAllSame) break;
    }

    if (isAllSame) {
        pieceCounts[colors[y][x] + 1]++;

        return;
    }

    int divider = size / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dncPiece(y + i * divider, x + j * divider, divider);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> colors[i][j];
        }
    }

    dncPiece(0, 0, n);

    cout << pieceCounts[0] << '\n' << pieceCounts[1] << '\n' << pieceCounts[2] << '\n';

    return 0;
}
