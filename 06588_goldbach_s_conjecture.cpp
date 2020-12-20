#include <iostream>
#include <vector>

using namespace std;

bool eratosthenesSieve[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> primes;

    for (int i = 2; i <= 1000000; i++) {
        if (!eratosthenesSieve[i]) {
            primes.push_back(i);

            for (int j = i + i; j <= 1000000; j += i) {
                eratosthenesSieve[j] = true;
            }
        }
    }

    while (true) {
        int even;

        cin >> even;

        if (even == 0) return 0;

        for (int i = 1; 2 * primes[i] <= even; i++) {
            if (!eratosthenesSieve[even - primes[i]]) {
                cout << even << " = " << primes[i] << " + " << even - primes[i] << '\n';

                break;
            }
        }
    }
}
