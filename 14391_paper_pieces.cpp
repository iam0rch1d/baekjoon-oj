#include <iostream>

using namespace std;

int main() {
    unsigned n;
    unsigned m;
    int digits[4][4];
    int maxPieceSum = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string digitString;

        cin >> digitString;

        for (int j = 0; j < m; j++) {
            digits[i][j] = digitString[j] - '0';
        }
    }

    for (unsigned isDigitVertical = 0; isDigitVertical < (1u << n * m); isDigitVertical++) {
        int pieceSum = 0;

        for (int i = 0; i < n; i++) {
            int piece = 0;

            for (int j = 0; j < m; j++) {
                if (!(isDigitVertical & (1u << (i * m + j)))) piece = piece * 10 + digits[i][j];
                else {
                    pieceSum += piece;
                    piece = 0;
                }
            }

            pieceSum += piece;
        }

        for (int j = 0; j < m; j++) {
            int piece = 0;

            for (int i = 0; i < n; i++) {
                if (isDigitVertical & (1u << (i * m + j))) piece = piece * 10 + digits[i][j];
                else {
                    pieceSum += piece;
                    piece = 0;
                }
            }

            pieceSum += piece;
        }

        maxPieceSum = max(maxPieceSum, pieceSum);
    }

    cout << maxPieceSum << '\n';

    return 0;
}
