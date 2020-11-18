#include <algorithm>
#include <iostream>

using namespace std;

int trees[1000000];

int main() {
    int n;
    long long m;
    long long cuttingSizeLeft = 0;
    long long cuttingSizeRight;
    long long maxCuttingSize = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    cuttingSizeRight = *max_element(trees, trees + n);

    while (cuttingSizeLeft <= cuttingSizeRight) {
        long long totalCutWood = 0;
        long long cuttingSizeMid = (cuttingSizeLeft + cuttingSizeRight) / 2;

        for (int i = 0; i < n; i++) {
            totalCutWood += trees[i] > cuttingSizeMid ? trees[i] - cuttingSizeMid : 0;
        }

        if (totalCutWood >= m) {
            maxCuttingSize = cuttingSizeMid;
            cuttingSizeLeft = cuttingSizeMid + 1;
        } else cuttingSizeRight = cuttingSizeMid - 1;
    }

    cout << maxCuttingSize << '\n';

    return 0;
}
