#include <iostream>

using namespace std;

int main() {
    int pieceOnWhiteCount = 0;

    for (int i = 0; i < 8; i++) {
        string boardRow;

        cin >> boardRow;

        for (int j = 0; j < 8; j++) {
            pieceOnWhiteCount += (i + j) % 2 == 0 && boardRow[j] == 'F';
        }
    }

    cout << pieceOnWhiteCount << '\n';

    return 0;
}
