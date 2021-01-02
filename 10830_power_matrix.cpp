#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

typedef vvl Matrix;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000

Matrix operator*=(Matrix &a, Matrix &b) {
    int size = a.size();
    Matrix ret(size, vl(size, 0));

    REP(i, size) REP(j, size) REP(k, size) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] % MODULO) % MODULO;

    return a = ret;
}

int main() {
    int baseSize;
    ll exponent;

    cin >> baseSize >> exponent;

    Matrix base(baseSize, vl(baseSize));
    Matrix ans(baseSize, vl(baseSize));

    REP(i, baseSize) REP(j, baseSize) cin >> base[i][j];

    REP(i, baseSize) ans[i][i] = 1;

    while (exponent > 0) {
        if (exponent % 2) ans *= base;

        base *= base;
        exponent /= 2;
    }

    REP (i, baseSize) {
        REP(j, baseSize) PRINT(ans[i][j]);

        PRINTLN("");
    }

    return 0;
}
