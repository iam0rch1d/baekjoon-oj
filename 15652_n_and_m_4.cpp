#include <iostream>

using namespace std;

int n;
int m;
int pickedNumberCounts[9];

void backtrackPickedNumbers(int pickCount, int toPickNumber) {
    if (pickCount == m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < pickedNumberCounts[i]; j++) {
                cout << i << ' ';
            }
        }

        cout << '\n';

        return;
    }

    if (toPickNumber > n) return;

    for (int i = m - pickCount; i >= 1; i--) {
        pickedNumberCounts[toPickNumber] = i;

        backtrackPickedNumbers(pickCount + i, toPickNumber + 1);
    }

    pickedNumberCounts[toPickNumber] = 0;

    backtrackPickedNumbers(pickCount, toPickNumber + 1);
}

int main() {
    cin >> n >> m;

    backtrackPickedNumbers(0, 1);

    return 0;
}
