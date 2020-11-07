#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> positives;
    vector<int> ones;
    vector<int> negatives;
    int positiveCount = 0;
    int oneCount = 0;
    int negativeCount = 0;
    int tiedSum = 0;

    cin >> n;

    while (n-- > 0) {
        int element;

        cin >> element;

        if (element >= 2) {
            positives.push_back(element);
            positiveCount++;
        } else if (element == 1) {
            ones.push_back(element);
            oneCount++;
        } else {
            negatives.push_back(element);
            negativeCount++;
        }
    }

    sort(positives.begin(), positives.end());
    sort(negatives.begin(), negatives.end(), greater<>());

    for (int i = 0; i < positiveCount; i += 2) {
        int tiedPair = 1;

        for (int j = 0; j < 2; j++) {
            if (!positives.empty()) {
                tiedPair *= positives.back();

                positives.pop_back();
            }
        }

        tiedSum += tiedPair;
    }

    for (int i = 0; i < oneCount; i++) {
        tiedSum += ones[i];
    }

    for (int i = 0; i < negativeCount; i += 2) {
        int tiedPair = 1;

        for (int j = 0; j < 2; j++) {
            if (!negatives.empty()) {
                tiedPair *= negatives.back();

                negatives.pop_back();
            }
        }

        if (!tiedPair) break;

        tiedSum += tiedPair;
    }

    cout << tiedSum << '\n';

    return 0;
}
