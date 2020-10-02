#include <algorithm>
#include <iostream>

using namespace std;

int trees[1000000];

int main() {
    int numTree;
    long long neededWood;
    long long cuttingSizeLow = 1;
    long long cuttingSizeHigh;
    long long maxCuttingSize = 0;

    cin >> numTree >> neededWood;

    for (int i = 0; i < numTree; i++) {
        cin >> trees[i];
    }

    cuttingSizeHigh = *max_element(trees, trees + numTree);

    while (cuttingSizeLow <= cuttingSizeHigh) {
        long long totalCutWood = 0;
        long long cuttingSizeCenter = (cuttingSizeLow + cuttingSizeHigh) / 2;

        for (int i = 0; i < numTree; i++) {
            totalCutWood += trees[i] > cuttingSizeCenter ? trees[i] - cuttingSizeCenter : 0;
        }

        if (totalCutWood >= neededWood) {
            maxCuttingSize = max(maxCuttingSize, cuttingSizeCenter);
            cuttingSizeLow = cuttingSizeCenter + 1;
        } else cuttingSizeHigh = cuttingSizeCenter - 1;
    }

    cout << maxCuttingSize << '\n';

    return 0;
}
