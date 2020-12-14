#include <iostream>
#include <vector>

using namespace std;

bool isSieved[1000001];

int main() {
    vector<int> primes;
    int t;

    for (int i = 2; i <= 1000000; i++) {
        if (!isSieved[i]) {
            primes.push_back(i);

            for (int j = i + i; j <= 1000000; j += i) {
                isSieved[j] = true;
            }
        }
    }

    cin >> t;

    while (t--) {
        int even;
        int partitionCount = 0;

        cin >> even;

        for (int i = 0; 2 * primes[i] <= even; i++) {
            if (!isSieved[even - primes[i]]) partitionCount++;
        }

        cout << partitionCount << '\n';
    }

    return 0;
}
