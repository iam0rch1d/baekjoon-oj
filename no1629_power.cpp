#include <iostream>

using namespace std;

long long int dncPower(int base, int exponent, int modulus) {
    if (exponent == 0) return 1;

    if (exponent % 2 != 0) return dncPower(base, exponent - 1, modulus) % modulus * base % modulus;

    return ((dncPower(base, exponent / 2, modulus) % modulus)
    * (dncPower(base, exponent / 2, modulus) % modulus))
    % modulus;
}

int main() {
    int base;
    int exponent;
    int modulus;

    cin >> base >> exponent >> modulus;

    cout << dncPower(base, exponent, modulus) << endl;

    return 0;
}
