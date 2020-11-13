#include <iostream>

using namespace std;

bool board[6561][6561];

void dncPicture(int sy, int sx, int n) {
    if (n == 1) {
        board[sy][sx] = true;

        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 || j != 1) dncPicture(sy + i * n / 3, sx + j * n / 3, n / 3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;

    cin >> n;

    dncPicture(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? '*' : ' ');
        }

        cout << '\n';
    }

    return 0;
}
