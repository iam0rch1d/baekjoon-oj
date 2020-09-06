#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

long long constructionCountCache[31][31];

long long memoizeConstructionCount(int numFromNode, int numToNode) {
    if (numFromNode == 0 || numFromNode == numToNode) return 1;

    long long &constructionCount = constructionCountCache[numFromNode][numToNode];

    if (constructionCount != UNMEMOIZED) return constructionCount;

    return constructionCount = memoizeConstructionCount(numFromNode - 1, numToNode - 1)
                               + memoizeConstructionCount(numFromNode, numToNode - 1);
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int numFromNode;
        int numToNode;

        cin >> numFromNode >> numToNode;

        memset(constructionCountCache, UNMEMOIZED, sizeof(constructionCountCache));

        cout << memoizeConstructionCount(numFromNode, numToNode) << endl;
    }

    return 0;
}
