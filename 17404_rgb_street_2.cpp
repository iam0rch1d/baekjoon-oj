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
int minimumTotalCostCache[1000][3];

int memoizeMinimumTotalCost(int from, int withColor, int firstColor) {
    if (from == numHouse - 1) {
        if (withColor == firstColor) return 1000001;

        return costs[from][withColor];
    }

    int &minimumTotalCost = minimumTotalCostCache[from][withColor];

    if (minimumTotalCost != UNMEMOIZED) return minimumTotalCost;

    return minimumTotalCost = costs[from][withColor]
                              + min(memoizeMinimumTotalCost(from + 1, (withColor + 1) % 3, firstColor),
                                    memoizeMinimumTotalCost(from + 1, (withColor + 2) % 3, firstColor));
}

int main() {
    int minimumTotalCost = 1000001;

    cin >> numHouse;

    for (int i = 0; i < numHouse; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    for (int i = 0; i < 3; i++) {
        memset(minimumTotalCostCache, UNMEMOIZED, sizeof(minimumTotalCostCache));

        minimumTotalCost = min(minimumTotalCost, memoizeMinimumTotalCost(0, i, i));
    }

    cout << minimumTotalCost << endl;

    return 0;
}
