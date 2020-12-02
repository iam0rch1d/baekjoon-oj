#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned n;
    int s;
    unsigned aFrontSize;
    unsigned aBackSize;
    unsigned frontsSize;
    unsigned backsSize;
    unsigned frontsHeadIndex = 0;
    unsigned backsHeadIndex = 0;
    long long sCount = 0;

    cin >> n >> s;

    aFrontSize = n / 2;
    aBackSize = n - aFrontSize;
    frontsSize = 1u << aFrontSize;
    backsSize = 1u << aBackSize;

    vector<int> aFront(aFrontSize);
    vector<int> aBack(aBackSize);
    vector<int> fronts(frontsSize);
    vector<int> backs(backsSize);

    for (int &ai : aFront) {
        cin >> ai;
    }

    for (int &ai : aBack) {
        cin >> ai;
    }

    for (unsigned bitset = 0; bitset < frontsSize; bitset++) {
        for (unsigned i = 0; i < aFrontSize; i++) {
            fronts[bitset] += bitset & (1u << i) ? aFront[i] : 0;
        }
    }

    for (unsigned bitset = 0; bitset < backsSize; bitset++) {
        for (unsigned i = 0; i < aBackSize; i++) {
            backs[bitset] += bitset & (1u << i) ? aBack[i] : 0;
        }
    }

    sort(fronts.begin(), fronts.end());
    sort(backs.rbegin(), backs.rend());

    while (frontsHeadIndex < frontsSize && backsHeadIndex < backsSize) {
        if (fronts[frontsHeadIndex] + backs[backsHeadIndex] == s) {
            long long frontCount = 1;
            long long backCount = 1;

            frontsHeadIndex++;
            backsHeadIndex++;

            while (frontsHeadIndex < frontsSize && fronts[frontsHeadIndex] == fronts[frontsHeadIndex - 1]) {
                frontCount++;
                frontsHeadIndex++;
            }

            while (backsHeadIndex < backsSize && backs[backsHeadIndex] == backs[backsHeadIndex - 1]) {
                backCount++;
                backsHeadIndex++;
            }

            sCount += frontCount * backCount;
        } else if (fronts[frontsHeadIndex] + backs[backsHeadIndex] < s) frontsHeadIndex++;
        else backsHeadIndex++;
    }

    cout << sCount - (s == 0) << '\n';

    return 0;
}
