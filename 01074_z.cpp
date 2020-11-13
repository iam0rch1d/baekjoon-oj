#include <iostream>

using namespace std;

unsigned dncVisitingOrder(unsigned y, unsigned x, unsigned n) {
    if (n == 1) return 2 * y + x;

    unsigned divider = 1u << (n - 1u);
    unsigned division = ((y >= divider) << 1u) + (x >= divider);

    return division * divider * divider + dncVisitingOrder(y % divider, x % divider, n - 1u);
}

int main() {
    unsigned n;
    unsigned r;
    unsigned c;

    cin >> n >> r >> c;
    cout << dncVisitingOrder(r, c, n) << '\n';

    return 0;
}
