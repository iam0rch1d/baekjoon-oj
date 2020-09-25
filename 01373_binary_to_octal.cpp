#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string binary;
    int binarySize;
    string octal;

    cin >> binary;

    binarySize = binary.size();

    reverse(binary.begin(), binary.end());

    binary += "000";

    for (int i = 0; i < binarySize; i += 3) {
        octal.push_back(binary[i] - '0' + 2 * (binary[i + 1] - '0') + 4 * (binary[i + 2] - '0') + '0');
    }

    reverse(octal.begin(), octal.end());

    cout << octal << '\n';

    return 0;
}
