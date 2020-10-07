#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numSign;
    vector<string> numberStrings;

    cin >> numSign;

    vector<char> signs(numSign);
    vector<bool> isNumberPicked(10, false);

    for (char &sign : signs) {
        cin >> sign;
    }

    for (int i = 0; i < numSign + 1; i++) {
        isNumberPicked[i] = true;
    }

    while (true) {
        string numberString;

        for (int i = 0; i < 10; i++) {
            if (isNumberPicked[i]) numberString += (char) ('0' + i);
        }

        while (true) {
            bool isSatisfied = true;

            for (int i = 0; i < numSign; i++) {
                if ((signs[i] == '<' && numberString[i] > numberString[i + 1])
                    || (signs[i] == '>' && numberString[i] < numberString[i + 1])) {
                    isSatisfied = false;

                    break;
                }
            }

            if (isSatisfied) numberStrings.push_back(numberString);

            if (!next_permutation(numberString.begin(), numberString.end())) break;
        }

        if (!prev_permutation(isNumberPicked.begin(), isNumberPicked.end())) break;
    }

    cout << numberStrings.back() << '\n' << numberStrings[0] << '\n';

    return 0;
}
