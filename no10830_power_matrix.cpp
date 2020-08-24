#include <iostream>
#include <vector>

#define MODULUS 1000

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix operator*(vector<vector<int>> &a, vector<vector<int>> &b) {
    int size = a.size();
    Matrix multiplication(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                multiplication[i][j] += a[i][k] * b[k][j];
            }

            multiplication[i][j] %= MODULUS;
        }
    }

    return multiplication;
}

Matrix powerMatrix(vector<vector<int>> &base, long long int exponent) {
    int baseSize = base.size();
    Matrix result(baseSize, vector<int>(baseSize, 0));

    for (int i = 0; i < baseSize; i++) {
        result[i][i] = 1;
    }

    while (exponent > 0) {
        if (exponent % 2 != 0) result = result * base;

        base = base * base;
        exponent /= 2;
    }

    return result;
}

int main() {
    int baseSize;
    long long int exponent;

    cin >> baseSize >> exponent;

    Matrix base(baseSize, vector<int>(baseSize));
    Matrix result(baseSize, vector<int>(baseSize));

    for (int i = 0; i < baseSize; i++) {
        for (int j = 0; j < baseSize; j++) {
            cin >> base[i][j];
        }
    }

    result = powerMatrix(base, exponent);

    for (int i = 0; i < baseSize; i++) {
        for (int j = 0; j < baseSize; j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
