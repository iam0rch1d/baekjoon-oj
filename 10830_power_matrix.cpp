#include <iostream>
#include <vector>

#define MODULO 1000

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix operator*(Matrix a, Matrix b) {
    int size = a.size();
    Matrix multiplication(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                multiplication[i][j] += a[i][k] * b[k][j];
            }

            multiplication[i][j] %= MODULO;
        }
    }

    return multiplication;
}

int main() {
    int baseSize;
    unsigned long long exponent;

    cin >> baseSize >> exponent;

    Matrix base(baseSize, vector<int>(baseSize));
    Matrix result(baseSize, vector<int>(baseSize));

    for (int i = 0; i < baseSize; i++) {
        for (int j = 0; j < baseSize; j++) {
            cin >> base[i][j];
        }
    }

    for (int i = 0; i < baseSize; i++) {
        result[i][i] = 1;
    }

    while (exponent > 0) {
        if (exponent % 2 == 1) result = result * base;

        base = base * base;
        exponent >>= 1u;
    }

    for (int i = 0; i < baseSize; i++) {
        for (int j = 0; j < baseSize; j++) {
            cout << result[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
