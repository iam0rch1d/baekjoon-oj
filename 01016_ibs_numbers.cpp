#include <iostream>
#include <vector>

using namespace std;

bool compositeSieve[1000001];
bool DbsSieve[1000001];  // 'DBS' refers to 'Divisible-By-Squares'

int main() {
    long long minimumX;
    long long maximumX;
    long long ibsNumberCount;  // 'IBS' refers to 'Indivisible-By-Squares'
    vector<long long> squares;

    cin >> minimumX >> maximumX;

    ibsNumberCount = maximumX - minimumX + 1;

    for (long long i = 2; i * i <= maximumX; i++) {
        if (compositeSieve[i]) continue;

        for (long long j = i; j * j <= maximumX; j += i) {
            compositeSieve[j] = true;
        }

        for (long long j = ((minimumX - 1) / (i * i) + 1) * i * i; j <= maximumX; j += i * i) {
            if (!DbsSieve[j - minimumX]) {
                DbsSieve[j - minimumX] = true;
                ibsNumberCount--;
            }
        }
    }

    cout << ibsNumberCount << endl;

    return 0;
}
