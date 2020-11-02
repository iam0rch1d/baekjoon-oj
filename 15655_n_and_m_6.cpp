#include <algorithm>
#include <iostream>

using namespace std;

int n;
int m;
int a[8];
bool isIndexPicked[8];

void backtrackPickedIndices(int pickCount, int toPickIndex) {
    if (pickCount == m) {
        for (int i = 0; i < n; i++) {
            if (isIndexPicked[i]) cout << a[i] << ' ';
        }

        cout << '\n';

        return;
    }

    if (toPickIndex >= n) return;

    isIndexPicked[toPickIndex] = true;

    backtrackPickedIndices(pickCount + 1, toPickIndex + 1);

    isIndexPicked[toPickIndex] = false;

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
