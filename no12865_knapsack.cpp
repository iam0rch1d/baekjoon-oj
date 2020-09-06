#include <iostream>

using namespace std;

int maximumTotalValueCache[101][100001];

int main() {
    int numItem;
    int strength;
    pair<int, int> items[100]; // .first = load, .second = value

    cin >> numItem >> strength;

    for (int i = 0; i < numItem; i++) {
        cin >> items[i].first >> items[i].second;
    }

    for (int i = 1; i <= numItem; i++) {
        for (int j = 1; j <= strength; j++) {
            if (items[i - 1].first <= j) {
                maximumTotalValueCache[i][j] = max(maximumTotalValueCache[i - 1][j - items[i - 1].first]
                                                   + items[i - 1].second,
                                                   maximumTotalValueCache[i - 1][j]);
            } else maximumTotalValueCache[i][j] = maximumTotalValueCache[i - 1][j];
        }
    }

    cout << maximumTotalValueCache[numItem][strength] << endl;

    return 0;
}
