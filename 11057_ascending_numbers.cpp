#include <iostream>
#include <vector>

#define MODULO 10007

using namespace std;

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
    int n;

    cin >> n;

    vector<long long> factorials(n + 10);

    factorials[0] = 1;
    factorials[1] = 1;

    for (int i = 2; i <= n + 9; i++) {
        factorials[i] = factorials[i - 1] * i % MODULO;
    }

    cout << factorials[n + 9]
            * power(factorials[n], MODULO - 2) % MODULO
            * power(factorials[9], MODULO - 2) % MODULO << '\n';

    return 0;
}
