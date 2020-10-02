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

int memoizeMinTotalCost(int toHouse, int withColor) {
    if (toHouse == 0) return costs[toHouse][withColor];

    int &minTotalCost = minTotalCostCache[toHouse][withColor];

    if (minTotalCost != UNMEMOIZED) return minTotalCost;

    return minTotalCost = costs[toHouse][withColor]
                          + min(memoizeMinTotalCost(toHouse - 1, (withColor + 1) % 3),
                                memoizeMinTotalCost(toHouse - 1, (withColor + 2) % 3));
}

int main() {
    cin >> numHouse;

    for (int i = 0; i < numHouse; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    memset(minTotalCostCache, UNMEMOIZED, sizeof(minTotalCostCache));

    cout << min({memoizeMinTotalCost(numHouse - 1, RED),
                 memoizeMinTotalCost(numHouse - 1, GREEN),
                 memoizeMinTotalCost(numHouse - 1, BLUE)}) << '\n';

    return 0;
}
