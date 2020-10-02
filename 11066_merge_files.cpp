#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int chapters[500];
int minMergeCostCache[500][500];

int memoizeMinMergeCost(int firstChapter, int lastChapter) {
    if (firstChapter == lastChapter) return 0;

    int &minMergeCost = minMergeCostCache[firstChapter][lastChapter];

    if (minMergeCost != UNMEMOIZED) return minMergeCost;

    int chapterSum = 0;

    for (int i = firstChapter; i <= lastChapter; i++) {
        chapterSum += chapters[i];
    }

    minMergeCost = 1073741823;

    for (int i = firstChapter; i <= lastChapter; i++) {
        minMergeCost = min(minMergeCost,
                           memoizeMinMergeCost(firstChapter, i) + memoizeMinMergeCost(i + 1, lastChapter) + chapterSum);
    }

    return minMergeCost;
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int numChapter;

        memset(minMergeCostCache, UNMEMOIZED, sizeof(minMergeCostCache));

        cin >> numChapter;

        for (int i = 0; i < numChapter; i++) {
            cin >> chapters[i];
        }

        cout << memoizeMinMergeCost(0, numChapter - 1) << '\n';
    }

    return 0;
}
