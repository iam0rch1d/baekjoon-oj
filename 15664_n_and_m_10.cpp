#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int a[8];
bool isIndexPicked[8];

void backtrackPickedIndices(vector<vector<int>> &pickedCombinations, int pickCount, int toPickIndex) {
    if (pickCount == m) {
        vector<int> pickedCombination;

        for (int i = 0; i < n; i++) {
            if (isIndexPicked[i]) pickedCombination.push_back(a[i]);
        }

        pickedCombinations.push_back(pickedCombination);

        return;
    }

    if (toPickIndex >= n) return;

    isIndexPicked[toPickIndex] = true;

    backtrackPickedIndices(pickedCombinations, pickCount + 1, toPickIndex + 1);

    isIndexPicked[toPickIndex] = false;

    backtrackPickedIndices(pickedCombinations, pickCount, toPickIndex + 1);
}

int main() {
    vector<vector<int>> pickedCombinations;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    backtrackPickedIndices(pickedCombinations, 0, 0);
    sort(pickedCombinations.begin(), pickedCombinations.end());
    pickedCombinations.erase(unique(pickedCombinations.begin(), pickedCombinations.end()), pickedCombinations.end());

    for (auto &pickedCombination : pickedCombinations) {
        for (int element : pickedCombination) {
            cout << element << ' ';
        }

        cout << '\n';
    }

    return 0;
}
