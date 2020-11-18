#include <iostream>

using namespace std;

long long countDigit(int n) {
    long long totalDigitCount = 0;
    long long nDigitCount = 1;
    long long divisor = 10;

    while (n >= divisor / 10) {
        totalDigitCount += nDigitCount * (n < divisor ? n - divisor / 10 + 1 : divisor / 10 * 9);
        nDigitCount++;
        divisor *= 10;
    }

    return totalDigitCount;
}

int main() {
    int n;
    int k;

    cin >> n >> k;

    if (countDigit(n) < k) {
        cout << "-1\n";

        return 0;
    }

    int lastWrittenLeft = 1;
    int lastWrittenRight = n;
    int lastWritten;

    while (lastWrittenLeft <= lastWrittenRight) {
        int lastWrittenMid = (lastWrittenLeft + lastWrittenRight) / 2;

        if (countDigit(lastWrittenMid) < k) lastWrittenLeft = lastWrittenMid + 1;
        else {
            lastWritten = lastWrittenMid;
            lastWrittenRight = lastWrittenMid - 1;
        }
    }

    string lastWrittenString = to_string(lastWritten);

    cout << lastWrittenString[k - countDigit(lastWritten - 1) - 1] << '\n';

    return 0;
}
