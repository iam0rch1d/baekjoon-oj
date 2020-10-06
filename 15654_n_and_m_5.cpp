#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int sequence[8];
bool isIndexPicked[8];

void backtrackPickedIndices(vector<int> &pickedIndices) {
    if (pickedIndices.size() == m) {
        for (int pickedIndex : pickedIndices) {
            cout << sequence[pickedIndex] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isIndexPicked[i]) {
            pickedIndices.push_back(i);

            isIndexPicked[i] = true;

            backtrackPickedIndices(pickedIndices);
            pickedIndices.pop_back();

            isIndexPicked[i] = false;
        }
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
