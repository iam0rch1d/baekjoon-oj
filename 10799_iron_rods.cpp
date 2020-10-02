#include <iostream>

using namespace std;

int main() {
    string brackets;
    int rodStack = -1;
    int totalPieceCount = 0;

    cin >> brackets;

    for (int i = 0; i < brackets.size(); i++) {
        if (brackets[i] == '(') rodStack++;
        else {
            if (brackets[i - 1] == '(') {
                totalPieceCount += rodStack;
            } else totalPieceCount++;

            rodStack--;
        }
    }

    cout << totalPieceCount << '\n';

    return 0;
}
