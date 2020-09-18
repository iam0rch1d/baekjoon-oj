#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int chapters[500];
int minimumMergeCostCache[500][500];

int memoizeMergeCost(int firstChapter, int lastChapter) {
    if (firstChapter == lastChapter) return 0;

    int &minimumMergeCost = minimumMergeCostCache[firstChapter][lastChapter];

    if (minimumMergeCost != UNMEMOIZED) return minimumMergeCost;

    int chapterSum = 0;

    for (int i = firstChapter; i <= lastChapter; i++) {
        chapterSum += chapters[i];
    }

    minimumMergeCost = 1073741823;

    for (int i = firstChapter; i <= lastChapter; i++) {
        minimumMergeCost = min(minimumMergeCost,
                               memoizeMergeCost(firstChapter, i) + memoizeMergeCost(i + 1, lastChapter) + chapterSum);
    }

    return minimumMergeCost;
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int numChapter;

        memset(minimumMergeCostCache, UNMEMOIZED, sizeof(minimumMergeCostCache));

        cin >> numChapter;

        for (int i = 0; i < numChapter; i++) {
            cin >> chapters[i];
        }

        cout << memoizeMergeCost(0, numChapter - 1) << endl;
    }

    return 0;
}
