#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

enum Color {
    RED = 0,
    GREEN,
    BLUE
};

int n;
int costs[1000][3];
int minTotalCostCache[1000][3];

int memoizeMinTotalCost(int toHouse, int withColor) {
    if (toHouse == 0) return costs[toHouse][withColor];

    int &minTotalCost = minTotalCostCache[toHouse][withColor];

    if (minTotalCost != UNKNOWN) return minTotalCost;

    return minTotalCost = costs[toHouse][withColor]
                          + min(memoizeMinTotalCost(toHouse - 1, (withColor + 1) % 3),
                                memoizeMinTotalCost(toHouse - 1, (withColor + 2) % 3));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    memset(minTotalCostCache, UNKNOWN, sizeof(minTotalCostCache));

    cout << min({memoizeMinTotalCost(n - 1, RED),
                 memoizeMinTotalCost(n - 1, GREEN),
                 memoizeMinTotalCost(n - 1, BLUE)}) << '\n';

    return 0;
}
