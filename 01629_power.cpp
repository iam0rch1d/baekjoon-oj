#include <iostream>

using namespace std;

long long dncPower(int base, int exponent, int modulo) {
    if (exponent == 0) return 1;

    if (exponent % 2 != 0) return dncPower(base, exponent - 1, modulo) % modulo * base % modulo;

    return ((dncPower(base, exponent / 2, modulo) % modulo)
            * (dncPower(base, exponent / 2, modulo) % modulo))
           % modulo;
}

int main() {
    int base;
    int exponent;
    int modulo;

    cin >> base >> exponent >> modulo;

    cout << dncPower(base, exponent, modulo) << '\n';

    return 0;
}
