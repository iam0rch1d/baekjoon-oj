#include <iostream>

using namespace std;

int main() {
    unsigned n;
    int s;
    int sequence[20];
    int subsequenceCount = 0;

    cin >> n >> s;

    for (unsigned i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (unsigned bitset = 1; bitset < (1u << n); bitset++) {
        int subsequenceSum = 0;

        for (unsigned i = 0; i < n; i++) {
            subsequenceSum += bitset & (1u << i) ? sequence[i] : 0;
        }

        if (subsequenceSum == s) subsequenceCount++;
    }

    cout << subsequenceCount << '\n';

    return 0;
}
