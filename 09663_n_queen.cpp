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

void backtrackNQueenCount(int row) {
    if (row == n) {
        nQueenCount++;

        return;
    }

    for (int i = 0; i < n; i++) {
        placedColumns[row] = i;

        if (isPromising({row, i})) backtrackNQueenCount(row + 1);
        else placedColumns[row] = -1;
    }
}

int main() {
    cin >> n;

    memset(placedColumns, -1, sizeof(placedColumns));
    backtrackNQueenCount(0);

    cout << nQueenCount << '\n';

    return 0;
}
