#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string n;
    int digitSum = 0;

    cin >> n;

    for (char nChar : n) {
        digitSum += nChar - '0';
    }

    sort(n.begin(), n.end(), greater<>());

    if (digitSum % 3 != 0 || n.back() != '0') {
        cout << "-1\n";

        return 0;
    }

    cout << n << '\n';

    return 0;
}
