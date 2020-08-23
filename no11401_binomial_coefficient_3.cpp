#include <iostream>
#include <vector>

#define MODULUS 1000000007

using namespace std;

long long int power(long long int base, long long int exponent) {
    long long int result = 1;

    while (exponent > 0) {
        if (exponent % 2 != 0) {
            result = result * base % MODULUS;
        }

        base = base * base % MODULUS;
        exponent /= 2;
    }

    return result;
}

int main() {
    int n;
    int k;

    cin >> n >> k;

    if (k == 0 || n == k) {
        cout << "1" << endl;

        return 0;
    }

    vector<long long int> factorials(n + 1);
    vector<long long int> factorialInverses(n + 1);

    factorials[0] = 1;
    factorials[1] = 1;

    for (int i = 2; i <= n; i++) {
        factorials[i] = factorials[i - 1] * i % MODULUS;
    }

    factorialInverses[n] = power(factorials[n], MODULUS - 2);

    for (int i = n - 1; i >= 0; i--) {
        factorialInverses[i] = factorialInverses[i + 1] * (i + 1) % MODULUS;
    }

    cout << factorials[n] * factorialInverses[k] % MODULUS * factorialInverses[n - k] % MODULUS << endl;

    return 0;
}
