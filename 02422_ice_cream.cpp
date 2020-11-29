#include <iostream>

using namespace std;

int isAdjacent[200][200];

int main() {
    int n;
    int m;
    int selectionCount = 0;

    cin >> n >> m;

    while (m--) {
        int x;
        int y;

        cin >> x >> y;

        isAdjacent[x - 1][y - 1] = true;
        isAdjacent[y - 1][x - 1] = true;
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                selectionCount += !(isAdjacent[i][j] || isAdjacent[j][k] || isAdjacent[k][i]);
            }
        }
    }

    cout << selectionCount << '\n';

    return 0;
}
