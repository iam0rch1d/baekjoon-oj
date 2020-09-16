#include <iostream>

#define MODULUS 1234567891

using namespace std;

long long power(long long base, long long exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 != 0) result = result * base % MODULUS;

        base = base * base % MODULUS;
        exponent /= 2;
    }

    return result;
}

int main() {
    int hashInputSize;
    string hashInput;
    long long hashOutput = 0;

    cin >> hashInputSize >> hashInput;

    for (int i = 0; i < hashInputSize; i++) {
        hashOutput = (hashOutput + (hashInput[i] - 'a' + 1) * power(31, i)) % MODULUS;
    }

    cout << hashOutput << endl;

    return 0;
}
