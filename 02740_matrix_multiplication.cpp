#include <iostream>
#include <vector>

using namespace std;

int main() {
    int aNumRow;
    int aNumColumn;
    int bNumColumn;

    cin >> aNumRow >> aNumColumn;

    vector<vector<int>> a(aNumRow, vector<int>(aNumColumn));

    for (int i = 0; i < aNumRow; i++) {
        for (int j = 0; j < aNumColumn; j++) {
            cin >> a[i][j];
        }
    }

    cin >> aNumColumn >> bNumColumn;

    vector<vector<int>> b(aNumColumn, vector<int>(bNumColumn));
    vector<vector<int>> multiplication(aNumRow, vector<int>(bNumColumn, 0));

    for (int i = 0; i < aNumColumn; i++) {
        for (int j = 0; j < bNumColumn; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < aNumRow; i++) {
        for (int j = 0; j < bNumColumn; j++) {
            for (int k = 0; k < aNumColumn; k++) {
                multiplication[i][j] += a[i][k] * b[k][j];
            }

            cout << multiplication[i][j] << ' ';
        }

        cout << '\n';
    }
}
