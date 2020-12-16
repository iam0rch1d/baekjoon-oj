#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
void chmin(T &m, T q) {
    m = min(m, q);
}

#define UNKNOWN -1

int chapters[500];
int minCostCache[500][500];

int memoizeMinCost(int left, int right) {
    if (left == right) return 0;

    int &minCost = minCostCache[left][right];

    if (minCost != UNKNOWN) return minCost;

    int chapterSum = 0;

    for (int i = left; i <= right; i++) {
        chapterSum += chapters[i];
    }

    minCost = 987654321;

    for (int i = left; i <= right; i++) {
        chmin(minCost, memoizeMinCost(left, i) + memoizeMinCost(i + 1, right));
    }

    return minCost += chapterSum;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int k;

        memset(minCostCache, UNKNOWN, sizeof(minCostCache));

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> chapters[i];
        }

        cout << memoizeMinCost(0, k - 1) << '\n';
    }

    return 0;
}
