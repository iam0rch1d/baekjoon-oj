#include <iostream>

using namespace std;

bool eratosthenesSieve[1000001];
bool squareNoNoSieve[1000001];

int main() {
    long long xMin;
    long long xMax;
    long long ans;

    cin >> xMin >> xMax;

    ans = xMax - xMin + 1;

    for (long long i = 2; i * i <= xMax; i++) {
        if (eratosthenesSieve[i]) continue;

        for (long long j = i; j * j <= xMax; j += i) {
            eratosthenesSieve[j] = true;
        }

        for (long long j = ((xMin - 1) / (i * i) + 1) * i * i; j <= xMax; j += i * i) {
            if (!squareNoNoSieve[j - xMin]) {
                squareNoNoSieve[j - xMin] = true;
                ans--;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
