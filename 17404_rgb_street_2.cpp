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

int memoizeMinTotalCost(int from, int withColor, int firstColor) {
    if (from == n - 1) return withColor == firstColor ? 1000001 : costs[from][withColor];

    int &minTotalCost = minTotalCostCache[from][withColor];

    if (minTotalCost != UNKNOWN) return minTotalCost;

    return minTotalCost = costs[from][withColor]
                          + min(memoizeMinTotalCost(from + 1, (withColor + 1) % 3, firstColor),
                                memoizeMinTotalCost(from + 1, (withColor + 2) % 3, firstColor));
}

int main() {
    int minTotalCost = 1000001;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    for (int i = 0; i < 3; i++) {
        memset(minTotalCostCache, UNKNOWN, sizeof(minTotalCostCache));

        minTotalCost = min(minTotalCost, memoizeMinTotalCost(0, i, i));
    }

    cout << minTotalCost << '\n';

    return 0;
}
