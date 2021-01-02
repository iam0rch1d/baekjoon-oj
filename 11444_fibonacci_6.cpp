#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000007

typedef vvl Matrix;

Matrix operator*=(Matrix &a, Matrix &b) {
    int size = a.size();
    Matrix ret(size, vl(size, 0));

    REP(i, size) REP(j, size) REP(k, size) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] % MODULO) % MODULO;

    return a = ret;
}

int main() {
    ll n;

    cin >> n;

    if (n <= 1) {
        PRINTLN(n);

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

    PRINTLN(ans[0][0]);

    return 0;
}
