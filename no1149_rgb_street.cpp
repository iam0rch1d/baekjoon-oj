#include <algorithm>
#include <iostream>
#include <vector>

#define UNMEMOIZED -1

enum Color {
    RED = 0,
    GREEN,
    BLUE
};

using namespace std;

int memoizeMinimumCostSum(vector<vector<int>> &costs,
                          vector<vector<int>> &minimumTotalCostCache,
                          int from,
                          int withColor) {
    if (from == costs.size() - 1) return costs[from][withColor];

    int &minimumTotalCost = minimumTotalCostCache[from][withColor];

    if (minimumTotalCost != UNMEMOIZED) return minimumTotalCost;

    return minimumTotalCost = costs[from][withColor]
                              + min(memoizeMinimumCostSum(costs, minimumTotalCostCache, from + 1, (withColor + 1) % 3),
                                    memoizeMinimumCostSum(costs, minimumTotalCostCache, from + 1, (withColor + 2) % 3));
}

int main() {
    int numHouse;

    cin >> numHouse;

    vector<vector<int>> costs(numHouse, vector<int>(3));
    vector<vector<int>> minimumTotalCostCache(numHouse, {UNMEMOIZED, UNMEMOIZED, UNMEMOIZED});

    for (int i = 0; i < numHouse; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    cout << min({memoizeMinimumCostSum(costs, minimumTotalCostCache, 0, RED),
                 memoizeMinimumCostSum(costs, minimumTotalCostCache, 0, GREEN),
                 memoizeMinimumCostSum(costs, minimumTotalCostCache, 0, BLUE)}) << endl;

    return 0;
}
