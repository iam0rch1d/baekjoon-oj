#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

vi operator+(vi &a, vi &b) {
    if (a.size() < b.size()) return operator+(b, a);

    int aSize = a.size();
    int bSize = b.size();

    vi ret(aSize, 0);
    int carry = 0;

    REP(i, aSize) {
        if (i < bSize) ret[i] += b[i];

        ret[i] += a[i] + carry;
        carry = ret[i] / 10;
        ret[i] %= 10;
    }

    if (carry != 0) ret.push_back(carry);

    return ret;
}

int main() {
    int n;

    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';

        return 0;
    }

    if (n >= 1 && n <= 2) {
        cout << 1 << '\n';

        return 0;
    }

    vi fibonacci;
    vi fibonacciPrev1 = {1};
    vi fibonacciPrev2 = {0};

    FOR_(i, 2, n) {
        fibonacci = fibonacciPrev1 + fibonacciPrev2;
        fibonacciPrev2 = fibonacciPrev1;
        fibonacciPrev1 = fibonacci;
    }

    int fibonacciSize = fibonacci.size();

    IFOR(i, 0, fibonacciSize) cout << fibonacci[i];

    PRINTLN("");

    return 0;
}
