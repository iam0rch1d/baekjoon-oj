#include <iostream>
#include <vector>

using namespace std;

bool eratosthenesSieve[4000001] = {true, true};

int main() {
    int n;
    vector<int> primes;
    int primesSize = 0;
    int primesSum;
    int left = 0;
    int right = 0;
    int nCount = 0;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (eratosthenesSieve[i]) continue;

        primes.push_back(i);
        primesSize++;

        for (int j = i + i; j <= n; j += i) {
            eratosthenesSieve[j] = true;
        }
    }

    primesSum = primes[0];

    while (right < primesSize) {
        if (primesSum <= n) {
            nCount += primesSum == n;
            primesSum += primes[++right];
        } else primesSum -= primes[left++];
    }

    cout << nCount << '\n';

    return 0;
}
