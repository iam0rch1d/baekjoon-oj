#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numWine;

    cin >> numWine;

    vector<int> wines(numWine);
    vector<int> maximumTotalAmountCache(numWine);

    for (int &wine : wines) {
        cin >> wine;
    }

    maximumTotalAmountCache[0] = wines[0];

    if (wines.size() == 1) {
        cout << maximumTotalAmountCache[0] << endl;

        return 0;
    }

    maximumTotalAmountCache[1] = wines[1] + wines[0];

    if (wines.size() == 2) {
        cout << maximumTotalAmountCache[1] << endl;

        return 0;
    }

    maximumTotalAmountCache[2] = max({wines[0] + wines[1], wines[0] + wines[2], wines[1] + wines[2]});

    if (wines.size() == 3) {
        cout << maximumTotalAmountCache[2] << endl;

        return 0;
    }

    for (int i = 3; i < numWine; i++) {
        maximumTotalAmountCache[i] = max({wines[i] + wines[i - 1] + maximumTotalAmountCache[i - 3],
                                         wines[i] + maximumTotalAmountCache[i - 2],
                                         maximumTotalAmountCache[i - 1]});
    }

    cout << maximumTotalAmountCache[numWine - 1] << endl;

    return 0;
}
