#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

enum Color {
    RED = 0,
    GREEN,
    BLUE
};

using namespace std;

int numHouse;
int costs[1000][3];
int minTotalCostCache[1000][3];

int memoizeMinTotalCost(int from, int withColor, int firstColor) {
    if (from == numHouse - 1) {
        if (withColor == firstColor) return 1000001;

        return costs[from][withColor];
    }

    int &minTotalCost = minTotalCostCache[from][withColor];

    if (minTotalCost != UNMEMOIZED) return minTotalCost;

    return minTotalCost = costs[from][withColor]
                          + min(memoizeMinTotalCost(from + 1, (withColor + 1) % 3, firstColor),
                                memoizeMinTotalCost(from + 1, (withColor + 2) % 3, firstColor));
}

int main() {
    int minTotalCost = 1000001;

    cin >> numHouse;

    for (int i = 0; i < numHouse; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    for (int i = 0; i < 3; i++) {
        memset(minTotalCostCache, UNMEMOIZED, sizeof(minTotalCostCache));

        minTotalCost = min(minTotalCost, memoizeMinTotalCost(0, i, i));
    }

    cout << minTotalCost << '\n';

    return 0;
}
