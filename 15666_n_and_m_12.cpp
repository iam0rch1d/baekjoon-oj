#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int sequence[8];
int pickedIndexCounts[8];

void backtrackPickedNumbers(vector<vector<int>> &pickedCombinations, int pickCount, int toPickIndex) {
    if (pickCount == m) {
        vector<int> pickedCombination;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < pickedIndexCounts[i]; j++) {
                pickedCombination.push_back(sequence[i]);
            }
        }

        pickedCombinations.push_back(pickedCombination);

        return;
    }

    if (toPickIndex >= n) return;

    for (int i = m - pickCount; i >= 1; i--) {
        pickedIndexCounts[toPickIndex] = i;

        backtrackPickedNumbers(pickedCombinations, pickCount + i, toPickIndex + 1);
    }

    pickedIndexCounts[toPickIndex] = 0;

    backtrackPickedNumbers(pickedCombinations, pickCount, toPickIndex + 1);
}

int main() {
    vector<vector<int>> pickedCombinations;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    sort(sequence, sequence + n);
    backtrackPickedNumbers(pickedCombinations, 0, 0);
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
