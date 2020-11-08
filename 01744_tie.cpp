#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> positives;
    int positiveCount = 0;
    int oneCount = 0;
    vector<int> negatives;
    int negativeCount = 0;
    int tiedSum = 0;

    cin >> n;

    while (n-- > 0) {
        int element;

        cin >> element;

        if (element >= 2) {
            positives.push_back(element);
            positiveCount++;
        } else if (element == 1) oneCount++;
        else {
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

    tiedSum += oneCount;

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
