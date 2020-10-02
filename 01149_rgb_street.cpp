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

int memoizeMinimumTotalCost(int toHouse, int withColor) {
    if (toHouse == 0) return costs[toHouse][withColor];

    int &minimumTotalCost = minimumTotalCostCache[toHouse][withColor];

    if (minimumTotalCost != UNMEMOIZED) return minimumTotalCost;

    return minimumTotalCost = costs[toHouse][withColor]
                              + min(memoizeMinimumTotalCost(toHouse - 1, (withColor + 1) % 3),
                                    memoizeMinimumTotalCost(toHouse - 1, (withColor + 2) % 3));
}

int main() {
    cin >> numHouse;

    for (int i = 0; i < numHouse; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    memset(minimumTotalCostCache, UNMEMOIZED, sizeof(minimumTotalCostCache));

    cout << min({memoizeMinimumTotalCost(numHouse - 1, RED),
                 memoizeMinimumTotalCost(numHouse - 1, GREEN),
                 memoizeMinimumTotalCost(numHouse - 1, BLUE)}) << endl;

    return 0;
}
