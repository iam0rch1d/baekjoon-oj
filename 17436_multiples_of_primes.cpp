#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned n;
    long long m;
    long long ans = 0;

    cin >> n >> m;

    vector<long long> primes(n);

    for (auto &prime : primes) {
        cin >> prime;
    }

    for (unsigned primeBitset = 1; primeBitset < (1u << n); primeBitset++) {
        long long factor = 1;
        int popcount = __builtin_popcount(primeBitset);

        for (unsigned i = 0; i < n; i++) {
            if (primeBitset & (1u << i)) factor *= primes[i];
        }

        ans += popcount % 2 ? m / factor : -m / factor;
    }

    cout << ans << '\n';

    return 0;
}
