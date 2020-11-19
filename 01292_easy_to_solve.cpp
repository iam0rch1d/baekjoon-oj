#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int numbers[1001];
    int toFill = 1;
    int fillCount = 0;
    int sum = 0;

    cin >> a >> b;

    for (int i = 1; i <= 1000; i++) {
        numbers[i] = toFill;

        if (++fillCount == toFill) {
            toFill++;
            fillCount = 0;
        }
    }

    for (int i = a; i <= b; i++) {
        sum += numbers[i];
    }

    cout << sum << '\n';

    return 0;
}
