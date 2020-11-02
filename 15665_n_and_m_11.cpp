#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int a[8];

void backtrackPickedNumbers(vector<vector<int>> &pickedPermutations, vector<int> &pickedNumbers) {
    if (pickedNumbers.size() == m) {
        pickedPermutations.push_back(pickedNumbers);

        return;
    }

    for (int i = 0; i < n; i++) {
        pickedNumbers.push_back(a[i]);
        backtrackPickedNumbers(pickedPermutations, pickedNumbers);
        pickedNumbers.pop_back();
    }
}

int main() {
    vector<vector<int>> pickedPermutations;
    vector<int> pickedNumbers;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    backtrackPickedNumbers(pickedPermutations, pickedNumbers);
    sort(pickedPermutations.begin(), pickedPermutations.end());
    pickedPermutations.erase(unique(pickedPermutations.begin(), pickedPermutations.end()), pickedPermutations.end());

    for (auto &pickedPermutation : pickedPermutations) {
        for (int element : pickedPermutation) {
            cout << element << ' ';
        }

        cout << '\n';
    }

    return 0;
}
