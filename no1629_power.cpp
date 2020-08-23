#include <iostream>

using namespace std;

long long int power(int base, int exponent, int modulus) {
    if (exponent == 0) return 1;

    if (exponent % 2 != 0) return power(base, exponent - 1, modulus) % modulus * base % modulus;

    return ((power(base, exponent / 2, modulus) % modulus) * (power(base, exponent / 2, modulus) % modulus)) % modulus;
}

int main() {
    int base;
    int exponent;
    int modulus;

    cin >> base >> exponent >> modulus;

    cout << power(base, exponent, modulus) << endl;

    return 0;
}
