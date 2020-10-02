#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numWine;

    cin >> numWine;

    vector<int> wines(numWine);
    vector<int> maxTotalAmountCache(numWine);

    for (int &wine : wines) {
        cin >> wine;
    }

    maxTotalAmountCache[0] = wines[0];

    if (wines.size() == 1) {
        cout << maxTotalAmountCache[0] << '\n';

        return 0;
    }

    maxTotalAmountCache[1] = wines[1] + wines[0];

    if (wines.size() == 2) {
        cout << maxTotalAmountCache[1] << '\n';

        return 0;
    }

    maxTotalAmountCache[2] = max({wines[0] + wines[1], wines[0] + wines[2], wines[1] + wines[2]});

    if (wines.size() == 3) {
        cout << maxTotalAmountCache[2] << '\n';

        return 0;
    }

    for (int i = 3; i < numWine; i++) {
        maxTotalAmountCache[i] = max({wines[i] + wines[i - 1] + maxTotalAmountCache[i - 3],
                                      wines[i] + maxTotalAmountCache[i - 2],
                                      maxTotalAmountCache[i - 1]});
    }

    cout << maxTotalAmountCache[numWine - 1] << '\n';

    return 0;
}
