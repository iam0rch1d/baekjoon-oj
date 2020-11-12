#include <iostream>

using namespace std;

bool board[3072][6144];

void dncPicture(int sy, int sx, int n) {
    if (n == 3) {
        board[sy][sx + 2] = true;
        board[sy + 1][sx + 1] = true;
        board[sy + 1][sx + 3] = true;
        board[sy + 2][sx] = true;
        board[sy + 2][sx + 1] = true;
        board[sy + 2][sx + 2] = true;
        board[sy + 2][sx + 3] = true;
        board[sy + 2][sx + 4] = true;

        return;
    }

    dncPicture(sy, sx + n / 2, n / 2);
    dncPicture(sy + n / 2, sx, n / 2);
    dncPicture(sy + n / 2, sx + n, n / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;

    cin >> n;

    dncPicture(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cout << (board[i][j] ? '*' : ' ');
        }

        cout << '\n';
    }

    return 0;
}
