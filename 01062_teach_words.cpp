#include <iostream>

using namespace std;

int n;
unsigned wordBitsets[50];

int backtrackReadable(unsigned alphabetNo, int leftAlphabetCount, unsigned taughtBitset) {
    if (leftAlphabetCount < 0) return 0;

    int readableCount = 0;

    if (alphabetNo == 26) {
        for (int i = 0; i < n; i++) {
            if (!(wordBitsets[i] & ((1u << 26u) - 1u - taughtBitset))) readableCount++;
        }

        return readableCount;
    }

    readableCount = backtrackReadable(alphabetNo + 1, leftAlphabetCount - 1, taughtBitset | (1u << alphabetNo));

    if (alphabetNo != 'a' - 'a'
        && alphabetNo != 'c' - 'a'
        && alphabetNo != 'i' - 'a'
        && alphabetNo != 'n' - 'a'
        && alphabetNo != 't' - 'a') {
        readableCount = max(readableCount, backtrackReadable(alphabetNo + 1, leftAlphabetCount, taughtBitset));
    }

    return readableCount;
}

int main() {
    int k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string word;
        unsigned wordBitset = 0;

        cin >> word;

        for (char letter : word) {
            wordBitset |= (1u << (unsigned) (letter - 'a'));
        }

        wordBitsets[i] = wordBitset;
    }

    cout << backtrackReadable(0, k, 0) << '\n';

    return 0;
}
