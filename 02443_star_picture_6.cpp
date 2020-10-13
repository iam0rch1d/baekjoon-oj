#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = n; i >= 1; i--) {
        string starRow(n - i, ' ');

        starRow += string(2 * i - 1, '*');

        cout << starRow << '\n';
    }

    return 0;
}
