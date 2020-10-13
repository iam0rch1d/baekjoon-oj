#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string starRow(n - i, ' ');

        starRow += string(2 * i - 1, '*');

        cout << starRow << '\n';
    }

    for (int i = n - 1; i >= 1; i--) {
        string starRow(n - i, ' ');

        starRow += string(2 * i - 1, '*');

        cout << starRow << '\n';
    }

    return 0;
}
