#include <cstring>
#include <iostream>

#define UNMEMOIZED -1
#define MODULO 1000000000

using namespace std;

long long binomialCoefficientCache[401][401];

long long memoizeBinomialCoefficient(int n, int k) {
    if (k == 0 || n == k) return 1;

    long long &binomialCoefficient = binomialCoefficientCache[n][k];

    if (binomialCoefficient != UNMEMOIZED) return binomialCoefficient;

    return binomialCoefficient = (memoizeBinomialCoefficient(n - 1, k - 1)
                                  + memoizeBinomialCoefficient(n - 1, k)) % MODULO;
}

int main() {
    int n;
    int k;

    memset(binomialCoefficientCache, UNMEMOIZED, sizeof(binomialCoefficientCache));

    cin >> n >> k;

    cout << memoizeBinomialCoefficient(n + k - 1, n) << '\n';

    return 0;
}
