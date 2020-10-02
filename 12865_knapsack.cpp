#include <iostream>

using namespace std;

int maxTotalValueCache[101][100001];

int main() {
    int numItem;
    int strength;
    pair<int, int> items[100];  // .first = <load>, .second = <value>

    cin >> numItem >> strength;

    for (int i = 0; i < numItem; i++) {
        cin >> items[i].first >> items[i].second;
    }

    for (int i = 1; i <= numItem; i++) {
        for (int j = 1; j <= strength; j++) {
            if (items[i - 1].first <= j) {
                maxTotalValueCache[i][j] = max(maxTotalValueCache[i - 1][j - items[i - 1].first] + items[i - 1].second,
                                               maxTotalValueCache[i - 1][j]);
            } else maxTotalValueCache[i][j] = maxTotalValueCache[i - 1][j];
        }
    }

    cout << maxTotalValueCache[numItem][strength] << '\n';

    return 0;
}
