#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int a[8];
bool isPicked[8];

void backtrackPickedNumbers(vector<vector<int>> &pickedPermutations, vector<int> &pickedNumbers) {
    if (pickedNumbers.size() == m) {
        pickedPermutations.push_back(pickedNumbers);

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isPicked[i]) {
            pickedNumbers.push_back(a[i]);

            isPicked[i] = true;

            backtrackPickedNumbers(pickedPermutations, pickedNumbers);
            pickedNumbers.pop_back();

            isPicked[i] = false;
        }
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

    for (const auto &pickedPermutation : pickedPermutations) {
        for (int pickedNumber : pickedPermutation) {
            cout << pickedNumber << ' ';
        }

        cout << '\n';
    }

    return 0;
}
