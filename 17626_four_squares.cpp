#include <iostream>

using namespace std;

int squareCountCache[50001];

int main() {
    int n;

    cin >> n;

    squareCountCache[0] = 1;

    for (int i = 1; i <= n; i++) {
        squareCountCache[i] = 5;

        for (int j = 1; j * j <= n; j++) {
            int previousNumber = i - j * j;

            if (previousNumber < 0 || squareCountCache[previousNumber] == 5) continue;

            squareCountCache[i] = min(squareCountCache[i], squareCountCache[previousNumber] + 1);
        }
    }

    cout << squareCountCache[n] - 1 << '\n';

    return 0;
}
