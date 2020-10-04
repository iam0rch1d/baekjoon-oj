#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int sequence[8];

void backtrackSubsequence(vector<int> &pickedIndices) {
    if (pickedIndices.size() == m) {
        for (int pickedIndex : pickedIndices) {
            cout << sequence[pickedIndex] << ' ';
        }

        cout << '\n';

        return;
    }

    int toPickIndex = pickedIndices.empty() ? 0 : pickedIndices.back();

    for (int i = toPickIndex; i < n; i++) {
        pickedIndices.push_back(i);
        backtrackSubsequence(pickedIndices);
        pickedIndices.pop_back();
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
