#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    string maxNumberString;
    string minNumberString;

    cin >> k;

    vector<char> signs(k);

    for (char &sign : signs) {
        cin >> sign;
    }

    for (int i = 0; i <= k; i++) {
        maxNumberString += (char) ('0' + (9 - i));
        minNumberString += (char) ('0' + i);
    }

    while (true) {
        bool isSatisfied = true;

        for (int i = 0; i < k; i++) {
            if ((signs[i] == '<' && maxNumberString[i] > maxNumberString[i + 1])
                || (signs[i] == '>' && maxNumberString[i] < maxNumberString[i + 1])) {
                isSatisfied = false;

                break;
            }
        }

        if (isSatisfied || !prev_permutation(maxNumberString.begin(), maxNumberString.end())) break;
    }

    while (true) {
        bool isSatisfied = true;

        for (int i = 0; i < k; i++) {
            if ((signs[i] == '<' && minNumberString[i] > minNumberString[i + 1])
                || (signs[i] == '>' && minNumberString[i] < minNumberString[i + 1])) {
                isSatisfied = false;

                break;
            }
        }

        if (isSatisfied || !next_permutation(minNumberString.begin(), minNumberString.end())) break;
    }

    cout << maxNumberString << '\n' << minNumberString << '\n';

    return 0;
}
