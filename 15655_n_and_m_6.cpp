#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int sequence[8];

void backtrackPickedIndices(vector<int> &pickedIndices) {
    if (pickedIndices.size() == m) {
        for (int pickedIndex : pickedIndices) {
            cout << sequence[pickedIndex] << ' ';
        }

        cout << '\n';

        return;
    }

    int toPickIndex = pickedIndices.empty() ? -1 : pickedIndices.back();

    for (int i = toPickIndex + 1; i < n; i++) {
        pickedIndices.push_back(i);
        backtrackPickedIndices(pickedIndices);
        pickedIndices.pop_back();
    }
}

int main() {
    vector<int> pickedIndices;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    sort(sequence, sequence + n);
    backtrackPickedIndices(pickedIndices);

    return 0;
}
