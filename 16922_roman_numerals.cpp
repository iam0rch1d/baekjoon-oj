#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int pickedRomanNumberCounts[4];

void backtrackRomanNumbers(vector<int> &values, int pickCount, int toPickIndex) {
    if (pickCount == n) {
        int value = 0;

        for (int i = 0; i < 4; i++) {
            value += pickedRomanNumberCounts[i] * (i % 2 == 1 ? 5 : 1) * (i >= 2 ? 10 : 1);
        }

        values.push_back(value);

        return;
    }

    if (toPickIndex >= 4) return;

    for (int i = n - pickCount; i >= 1; i--) {
        pickedRomanNumberCounts[toPickIndex] = i;

        backtrackRomanNumbers(values, pickCount + i, toPickIndex + 1);
    }

    pickedRomanNumberCounts[toPickIndex] = 0;

    backtrackRomanNumbers(values, pickCount, toPickIndex + 1);
}

int main() {
    vector<int> values;

    cin >> n;

    backtrackRomanNumbers(values, 0, 0);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    cout << values.size() << '\n';

    return 0;
}
