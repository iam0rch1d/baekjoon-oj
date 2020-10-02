#include <iostream>
#include <vector>

using namespace std;

bool eratosthenesSieve[1000001];
bool DbsSieve[1000001];  // 'DBS' refers to 'Divisible-By-Squares'

int main() {
    long long minX;
    long long maxX;
    long long ibsNumberCount;  // 'IBS' refers to 'Indivisible-By-Squares'
    vector<long long> squares;

    cin >> minX >> maxX;

    ibsNumberCount = maxX - minX + 1;

    for (long long i = 2; i * i <= maxX; i++) {
        if (eratosthenesSieve[i]) continue;

        for (long long j = i; j * j <= maxX; j += i) {
            eratosthenesSieve[j] = true;
        }

        for (long long j = ((minX - 1) / (i * i) + 1) * i * i; j <= maxX; j += i * i) {
            if (!DbsSieve[j - minX]) {
                DbsSieve[j - minX] = true;
                ibsNumberCount--;
            }
        }
    }

    cout << ibsNumberCount << '\n';

    return 0;
}
