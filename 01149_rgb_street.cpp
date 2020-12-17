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
int dp[1000][3];

int memoize(int house, int color) {
    if (house == 0) return costs[house][color];

    int &ret = dp[house][color];

    if (ret != UNKNOWN) return ret;

    return ret = costs[house][color] + min(memoize(house - 1, (color + 1) % 3), memoize(house - 1, (color + 2) % 3));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> costs[i][RED] >> costs[i][GREEN] >> costs[i][BLUE];
    }

    memset(dp, UNKNOWN, sizeof(dp));

    cout << min({memoize(n - 1, RED), memoize(n - 1, GREEN), memoize(n - 1, BLUE)}) << '\n';

    return 0;
}
