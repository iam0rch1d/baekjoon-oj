#include <iostream>

using namespace std;

#define MODULO 1234567891

long long power(long long base, long long exponent) {
    long long ret = 1;

    while (exponent > 0) {
        if (exponent % 2 != 0) ret = ret * base % MODULO;

        base = base * base % MODULO;
        exponent /= 2;
    }

    return ret;
}

int main() {
    int hashInputSize;
    string hashInput;
    long long hashOutput = 0;

    cin >> hashInputSize >> hashInput;

    for (int i = 0; i < hashInputSize; i++) {
        hashOutput = (hashOutput + (hashInput[i] - 'a' + 1) * power(31, i)) % MODULO;
    }

    cout << hashOutput << '\n';

    return 0;
}
