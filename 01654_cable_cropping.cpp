#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    long long n;
    long long croppingSizeLeft = 1;
    long long croppingSizeRight;
    long long maxCroppingSize = 0;

    cin >> k >> n;

    vector<long long> ownedCables(k);

    for (auto &ownedCable : ownedCables) {
        cin >> ownedCable;
    }

    croppingSizeRight = *max_element(ownedCables.begin(), ownedCables.end());

    while (croppingSizeLeft <= croppingSizeRight) {
        long long croppedCables = 0;
        long long croppingSizeMid = (croppingSizeLeft + croppingSizeRight) / 2;

        for (auto ownedCable : ownedCables) {
            croppedCables += ownedCable / croppingSizeMid;
        }

        if (croppedCables >= n) {
            maxCroppingSize = max(maxCroppingSize, croppingSizeMid);
            croppingSizeLeft = croppingSizeMid + 1;
        } else croppingSizeRight = croppingSizeMid - 1;
    }

    cout << maxCroppingSize << '\n';

    return 0;
}
