#include <iostream>
#include <vector>

using namespace std;

int n;
int m;

void backtrackPickedNumbers(vector<int> &pickedNumbers) {
    if (pickedNumbers.size() == m) {
        for (int pickedNumber : pickedNumbers) {
            cout << pickedNumber << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; i++) {
        pickedNumbers.push_back(i);
        backtrackPickedNumbers(pickedNumbers);
        pickedNumbers.pop_back();
    }
}

int main() {
    vector<int> pickedNumbers;

    cin >> n >> m;

    backtrackPickedNumbers(pickedNumbers);

    return 0;
}
