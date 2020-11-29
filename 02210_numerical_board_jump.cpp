#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int board[5][5];
set<int> paths;

void backtrackPath(int jumps, int path, int y, int x) {
    if (jumps == 5) {
        paths.insert(path);

        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + "1201"[i] - '1';
        int nx = x + "0112"[i] - '1';

        if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) backtrackPath(jumps + 1, path * 10 + board[ny][nx], ny, nx);
    }
}

int main() {
    for (auto &boardRow : board) {
        for (int &boardElement : boardRow) {
            cin >> boardElement;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            backtrackPath(0, board[i][j], i, j);
        }
    }

    cout << paths.size() << '\n';

    return 0;
}
