#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
bool isNumberPicked[9];

void backtrackPickedNumbers(vector<int> &pickedNumbers) {
    if (pickedNumbers.size() == m) {
        for (int pickedNumber : pickedNumbers) {
            cout << pickedNumber << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isNumberPicked[i]) {
            pickedNumbers.push_back(i);

            isNumberPicked[i] = true;

            backtrackPickedNumbers(pickedNumbers);
            pickedNumbers.pop_back();

            isNumberPicked[i] = false;
        }
    }
}

int main() {
    vector<int> pickedNumbers;

    cin >> n >> m;

    backtrackPickedNumbers(pickedNumbers);

    return 0;
}
