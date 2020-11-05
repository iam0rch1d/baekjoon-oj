#include <algorithm>
#include <iostream>

using namespace std;

int digitCounts[10];

int main() {
    string n;

    cin >> n;

    for (char digit : n) {
        digitCounts[digit == '6' ? 9 : digit - '0']++;
    }

    cout << max((digitCounts[9] + 1) / 2, *max_element(digitCounts, digitCounts + 9)) << '\n';

    return 0;
}
