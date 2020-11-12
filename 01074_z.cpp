#include <iostream>

using namespace std;

unsigned dncZVisit(unsigned n, unsigned y, unsigned x) {
    if (n == 1) return 2 * y + x;

    unsigned divider = 1u << (n - 1u);
    unsigned visitingOrder = ((y >= divider) << 1u) + (x >= divider);
    unsigned division = divider * divider;

    return visitingOrder * division + dncZVisit(n - 1u, y - (y >= divider) * divider, x - (x >= divider) * divider);
}

int main() {
    unsigned n;
    unsigned r;
    unsigned c;

    cin >> n >> r >> c;
    cout << dncZVisit(n, r, c) << '\n';

    return 0;
}
