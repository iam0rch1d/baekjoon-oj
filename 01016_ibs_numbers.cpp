#include <iostream>

using namespace std;

bool isSieved[1000001];
bool isDbsSieved[1000001];  // 'DBS' refers to 'Divisible-By-Squares'

int main() {
    long long minX;
    long long maxX;
    long long ibsNumberCount;  // 'IBS' refers to 'Indivisible-By-Squares'

    cin >> minX >> maxX;

    ibsNumberCount = maxX - minX + 1;

    for (long long i = 2; i * i <= maxX; i++) {
        if (isSieved[i]) continue;

        for (long long j = i; j * j <= maxX; j += i) {
            isSieved[j] = true;
        }

        for (long long j = ((minX - 1) / (i * i) + 1) * i * i; j <= maxX; j += i * i) {
            if (!isDbsSieved[j - minX]) {
                isDbsSieved[j - minX] = true;
                ibsNumberCount--;
            }
        }
    }

    cout << ibsNumberCount << '\n';

    return 0;
}
