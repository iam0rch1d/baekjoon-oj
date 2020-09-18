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

int memoizeMinimumTotalCost(int from, int withColor) {
    if (from == numHouse - 1) return costs[from][withColor];

    int &minimumTotalCost = minimumTotalCostCache[from][withColor];

    if (minimumTotalCost != UNMEMOIZED) return minimumTotalCost;

    return minimumTotalCost = costs[from][withColor]
                              + min(memoizeMinimumTotalCost(from + 1, (withColor + 1) % 3),
                                    memoizeMinimumTotalCost(from + 1, (withColor + 2) % 3));
}

int main() {
    cin >> numHouse;

    for (int i = 0; i < numHouse; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    memset(minimumTotalCostCache, UNMEMOIZED, sizeof(minimumTotalCostCache));

    cout << min({memoizeMinimumTotalCost(0, RED),
                 memoizeMinimumTotalCost(0, GREEN),
                 memoizeMinimumTotalCost(0, BLUE)}) << endl;

    return 0;
}
