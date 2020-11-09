#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r;
    int c;

    cin >> r >> c;

    vector<vector<int>> board(r, vector<int>(c));

    for (auto &boardRow : board) {
        for (int &boardElement : boardRow) {
            cin >> boardElement;
        }
    }

    if (r % 2) {
        for (int i = 0; i < r; i++) {
            if (i % 2 == 0) cout << string(c - 1, 'R') + "D "[i == r - 1];
            else cout << string(c - 1, 'L') + 'D';
        }
    } else if (c % 2) {
        for (int i = 0; i < c; i++) {
            if (i % 2 == 0) cout << string(r - 1, 'D') + "R "[i == c - 1];
            else cout << string(r - 1, 'U') + 'R';
        }
    } else {
        int yPrime = 0;
        int xPrime = 1;
        int y1 = 0;
        int x1 = 0;
        int y2 = r - 1;
        int x2 = c - 1;
        string s1;
        string s2;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i + j) % 2 && board[i][j] < board[yPrime][xPrime]) {
                    yPrime = i;
                    xPrime = j;
                }
            }
        }

        while (y2 - y1 > 1) {
            if (y1 / 2 < yPrime / 2) {
                s1 += string(c - 1, 'R') + 'D' + string(c - 1, 'L') + 'D';
                y1 += 2;
            }

            if (yPrime / 2 < y2 / 2) {
                s2 += string(c - 1, 'R') + 'D' + string(c - 1, 'L') + 'D';
                y2 -= 2;
            }
        }

        while (x2 - x1 > 1) {
            if (x1 / 2 < xPrime / 2) {
                s1 += "DRUR";
                x1 += 2;
            }

            if (xPrime / 2 < x2 / 2) {
                s2 += "DRUR";
                x2 -= 2;
            }
        }

        s1 += x1 == xPrime ? "RD" : "DR";

        cout << s1;

        reverse(s2.begin(), s2.end());

        cout << s2;
    }

    cout << '\n';

    return 0;
}
