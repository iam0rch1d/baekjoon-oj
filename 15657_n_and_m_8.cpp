#include <algorithm>
#include <iostream>

using namespace std;

int n;
int m;
int a[8];
int pickedIndexCounts[8];

void backtrackPickedIndices(int pickCount, int toPickIndex) {
    if (pickCount == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < pickedIndexCounts[i]; j++) {
                cout << a[i] << ' ';
            }
        }

        cout << '\n';

        return;
    }

    if (toPickIndex >= n) return;

    for (int i = m - pickCount; i >= 1; i--) {
        pickedIndexCounts[toPickIndex] = i;

        backtrackPickedIndices(pickCount + i, toPickIndex + 1);
    }

    pickedIndexCounts[toPickIndex] = 0;

    backtrackPickedIndices(pickCount, toPickIndex + 1);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    backtrackPickedIndices(0, 0);

    return 0;
}
