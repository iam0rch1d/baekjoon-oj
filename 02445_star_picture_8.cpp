#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string starRow(i, '*');

        starRow += string(2 * (n - i), ' ') + string(i, '*');

        cout << starRow << '\n';
    }

    for (int i = n - 1; i >= 1; i--) {
        string starRow(i, '*');

        starRow += string(2 * (n - i), ' ') + string(i, '*');

        cout << starRow << '\n';
    }

    return 0;
}
