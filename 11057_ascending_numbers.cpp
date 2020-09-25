#include <iostream>
#include <vector>

#define MODULO 10007

using namespace std;

long long power(long long base, long long exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 != 0) result = result * base % MODULO;

        base = base * base % MODULO;
        exponent /= 2;
    }

    return result;
}

int main() {
    int n;
    int k = 9;

    cin >> n;

    n += 9;
    k = (k > n - k) ? n - k : k;

    if (k == 0) {
        cout << "1" << endl;

        return 0;
    }

    if (k == 1) {
        cout << n << endl;

        return 0;
    }

    vector<long long> factorials(n + 1);

    factorials[0] = 1;
    factorials[1] = 1;

    for (int i = 2; i <= n; i++) {
        factorials[i] = factorials[i - 1] * i % MODULO;
    }

    cout << factorials[n]
            * power(factorials[k], MODULO - 2) % MODULO
            * power(factorials[n - k], MODULO - 2) % MODULO
         << endl;

    return 0;
}