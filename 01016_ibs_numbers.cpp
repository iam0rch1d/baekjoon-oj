#include <iostream>
#include <vector>

using namespace std;

bool isComposite[1000001];
bool isNumberDbs[1000001];  // 'BSS' refers to 'Divisible-By-Squares'

int main() {
    long long minimumX;
    long long maximumX;
    long long ibsNumberCount;  // 'IBAS' refers to 'Indivisible-By-Squares'
    vector<long long> squares;

    cin >> minimumX >> maximumX;

    ibsNumberCount = maximumX - minimumX + 1;

    for (long long i = 2; i * i <= maximumX; i++) {
        if (isComposite[i]) continue;

        for (long long j = i; j * j <= maximumX; j += i) {
            isComposite[j] = true;
        }

        for (long long j = ((minimumX - 1) / (i * i) + 1) * i * i; j <= maximumX; j += i * i) {
            if (!isNumberDbs[j - minimumX]) {
                isNumberDbs[j - minimumX] = true;
                ibsNumberCount--;
            }
        }
    }

    cout << ibsNumberCount << endl;

    return 0;
}
