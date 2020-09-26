#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long decimal;
    string minusBinary;

    cin >> decimal;

    if (decimal == 0) {
        cout << "0\n";

        return 0;
    }

    while (decimal != 0) {
        if (decimal % 2 == 0) {
            minusBinary += '0';
            decimal /= -2;
        } else {
            minusBinary += '1';
            decimal = (decimal - 1) / -2;
        }
    }

    reverse(minusBinary.begin(), minusBinary.end());

    cout << minusBinary << '\n';

    return 0;
}
