#include <iostream>
#include <vector>

#define MODULUS 1000000

using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix operator*(Matrix &a, Matrix &b) {
    int size = a.size();
    Matrix multiplication(size, vector<long long>(size));

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

Matrix powerMatrix(Matrix &base, long long exponent) {
    int baseSize = base.size();
    Matrix result(baseSize, vector<long long>(baseSize, 0));

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
    long long index;

    cin >> index;

    if (index < 2) {
        cout << index << endl;

        return 0;
    }

    Matrix base = {{0, 1}, {1, 1}};

    cout << powerMatrix(base, index - 1)[1][1] << endl;

    return 0;
}
