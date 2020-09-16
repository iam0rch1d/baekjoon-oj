#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int placedColumns[15];
int nQueenCount;

bool isPromising(pair<int, int> point) {
    for (int i = 0; i < point.first; i++) {
        if (point.second == placedColumns[i]
            || abs(point.first - i) == abs(point.second - placedColumns[i])) {
            return false;
        }
    }

    return true;
}

void backtrackNQueenCount(int currentRow) {
    if (currentRow == n) {
        nQueenCount++;

        return;
    }

    for (int i = 0; i < n; i++) {
        placedColumns[currentRow] = i;

        if (isPromising({currentRow, i})) backtrackNQueenCount(currentRow + 1);
        else placedColumns[currentRow] = -1;
    }
}

int main() {
    cin >> n;

    memset(placedColumns, -1, sizeof(placedColumns));
    backtrackNQueenCount(0);

    cout << nQueenCount << endl;

    return 0;
}
