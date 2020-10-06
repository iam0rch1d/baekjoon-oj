#include <iostream>

using namespace std;

int n;
int m;
bool isNumberPicked[9];

void backtrackPickedNumbers(int pickCount, int toPickNumber) {
    if (pickCount == m) {
        for (int i = 1; i <= n; i++) {
            if (isNumberPicked[i]) cout << i << ' ';
        }

        cout << '\n';

        return;
    }

    if (toPickNumber > n) return;

    isNumberPicked[toPickNumber] = true;

    backtrackPickedNumbers(pickCount + 1, toPickNumber + 1);

    isNumberPicked[toPickNumber] = false;

    backtrackPickedNumbers(pickCount, toPickNumber + 1);
}

int main() {
    cin >> n >> m;

    backtrackPickedNumbers(0, 1);

    return 0;
}
