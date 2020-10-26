#include <algorithm>
#include <iostream>

using namespace std;

bool canMake[2000001];

int main() {
    unsigned n;
    int sequence[20];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (unsigned bitset = 1; bitset < (1u << n); bitset++) {
        int subsequenceSum = 0;

        for (unsigned i = 0; i < n; i++) {
            subsequenceSum += bitset & (1u << i) ? sequence[i] : 0;
        }

        canMake[subsequenceSum] = true;
    }

    for (int i = 1; i <= 2000000; i++) {
        if (!canMake[i]) {
            cout << i << '\n';

            return 0;
        }
    }
}
