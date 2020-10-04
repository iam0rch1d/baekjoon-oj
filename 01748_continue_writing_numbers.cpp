#include <iostream>

using namespace std;

int main() {
    int n;
    int totalDigitCount = 0;
    int nDigitCount = 1;
    int divisor = 10;

    cin >> n;

    while (n >= divisor / 10) {
        totalDigitCount += nDigitCount * (n < divisor ? n - divisor / 10 + 1 : divisor / 10 * 9);

        nDigitCount++;
        divisor *= 10;
    }

    cout << totalDigitCount << '\n';

    return 0;
}
