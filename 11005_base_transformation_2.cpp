#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long decimal;
    int base;
    string transformed;

    cin >> decimal >> base;

    if (decimal == 0) {
        cout << "0\n";

        return 0;
    }

    while (decimal > 0) {
        long long transformedDigit = decimal % base;

        if (transformedDigit >= 0 && transformedDigit <= 9) transformed += (char) (transformedDigit + '0');
        else transformed += (char) (transformedDigit - 10 + 'A');

        decimal /= base;
    }

    reverse(transformed.begin(), transformed.end());

    cout << transformed << '\n';

    return 0;
}
