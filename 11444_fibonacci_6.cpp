#include <iostream>
#include <vector>

using namespace std;

#define MODULO 1000000007

typedef vector<vector<long long>> Matrix;

Matrix operator*=(Matrix &a, Matrix &b) {
    int size = a.size();
    Matrix multiplication(size, vector<long long>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                multiplication[i][j] += a[i][k] * b[k][j];
            }

            multiplication[i][j] %= MODULO;
        }
    }

    return a = multiplication;
}

int main() {
    long long n;

    cin >> n;

    if (n <= 1) {
        cout << n << '\n';

        return 0;
    }

    n--;

    Matrix ans = {{1, 0},
                  {0, 1}};
    Matrix base = {{1, 1},
                   {1, 0}};

    while (n) {
        if (n % 2) ans *= base;

        base *= base;
        n /= 2;
    }

    cout << ans[0][0] << '\n';

    return 0;
}
