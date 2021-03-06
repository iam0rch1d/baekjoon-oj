#include <iostream>
#include <vector>

using namespace std;

bool eratosthenesSieve[1000001];

int main() {
    vector<int> primes;
    int tc;

    for (int i = 2; i <= 1000000; i++) {
        if (!eratosthenesSieve[i]) {
            primes.push_back(i);

            for (int j = i + i; j <= 1000000; j += i) {
                eratosthenesSieve[j] = true;
            }
        }
    }

    cin >> tc;

    while (tc--) {
        int even;
        int partitionCount = 0;

        cin >> even;

        for (int i = 0; 2 * primes[i] <= even; i++) {
            if (!eratosthenesSieve[even - primes[i]]) partitionCount++;
        }

        cout << partitionCount << '\n';
    }

    return 0;
}
