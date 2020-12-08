#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string a;
    string t;
    string aReversed;
    unsigned long long left = 0;
    unsigned long long right;
    unsigned long long aSize;
    bool isFromLeft = true;
    string leftCensor;
    string rightCensor;

    cin >> a >> t;

    aReversed = a;

    reverse(aReversed.begin(), aReversed.end());

    right = t.size();
    aSize = a.size();

    while (left < right) {
        if (isFromLeft) {
            leftCensor.push_back(t[left++]);

            if (leftCensor.size() >= aSize && leftCensor.substr(leftCensor.size() - aSize, aSize) == a) {
                for (int i = 0; i < aSize; i++) {
                    leftCensor.pop_back();
                }

                isFromLeft = !isFromLeft;
            }
        } else {
            rightCensor.push_back(t[--right]);

            if (rightCensor.size() >= aSize && rightCensor.substr(rightCensor.size() - aSize, aSize) == aReversed) {
                for (int i = 0; i < aSize; i++) {
                    rightCensor.pop_back();
                }

                isFromLeft = !isFromLeft;
            }
        }
    }

    while (!rightCensor.empty()) {
        leftCensor.push_back(rightCensor.back());
        rightCensor.pop_back();

        if (leftCensor.size() >= aSize && leftCensor.substr(leftCensor.size() - aSize, aSize) == a) {
            for (int i = 0; i < aSize; i++) {
                leftCensor.pop_back();
            }
        }
    }

    cout << leftCensor << '\n';

    return 0;
}
