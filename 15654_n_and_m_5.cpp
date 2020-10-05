#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int sequence[8];
bool isPicked[8];

void backtrackSubsequence(vector<int> &pickedIndices) {
    if (pickedIndices.size() == m) {
        for (int pickedIndex : pickedIndices) {
            cout << sequence[pickedIndex] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isPicked[i]) {
            pickedIndices.push_back(i);

            isPicked[i] = true;

            backtrackSubsequence(pickedIndices);
            pickedIndices.pop_back();

            isPicked[i] = false;
        }
    }
}

int main() {
    vector<int> pickedNumbers;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    sort(sequence, sequence + n);
    backtrackSubsequence(pickedNumbers);

    return 0;
}
