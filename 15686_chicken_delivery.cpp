#include <iostream>
#include <vector>

using namespace std;

int calculateChickenDistance(pair<int, int> house, pair<int, int> chickenzip) {
    return abs(chickenzip.second - house.second) + abs(chickenzip.first - house.first);
}

int main() {
    int n;
    int m;
    int mapElement;
    vector<pair<int, int>> houses;
    vector<pair<int, int>> chickenzips;
    unsigned chickenzipCount = 0;
    int minTotalChickenDistance = 5001;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mapElement;

            if (mapElement == 1) houses.emplace_back(i, j);
            else if (mapElement == 2) {
                chickenzips.emplace_back(i, j);

                chickenzipCount++;
            }
        }
    }

    for (unsigned aliveBitset = 0; aliveBitset < (1u << chickenzipCount); aliveBitset++) {
        if (__builtin_popcount(aliveBitset) != m) continue;

        int totalChickenDistance = 0;

        for (auto house : houses) {
            int chickenDistance = 5001;

            for (unsigned i = 0; i < chickenzipCount; i++) {
                if (aliveBitset & (1u << i)) {
                    chickenDistance = min(chickenDistance, calculateChickenDistance(house, chickenzips[i]));
                }
            }

            totalChickenDistance += chickenDistance;
        }

        minTotalChickenDistance = min(minTotalChickenDistance, totalChickenDistance);
    }

    cout << minTotalChickenDistance << '\n';

    return 0;
}
