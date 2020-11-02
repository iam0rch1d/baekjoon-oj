#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int a[8];

void backtrackPickedIndices(vector<int> &pickedIndices) {
    if (pickedIndices.size() == m) {
        for (int pickedIndex : pickedIndices) {
            cout << a[pickedIndex] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++) {
        pickedIndices.push_back(i);
        backtrackPickedIndices(pickedIndices);
        pickedIndices.pop_back();
    }
}

int main() {
    vector<int> pickedIndices;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    backtrackPickedIndices(pickedIndices);

    return 0;
}
