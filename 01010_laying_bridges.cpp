#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1

long long constructionCountCache[31][31];

long long memoizeConstructionCount(int numFromNode, int numToNode) {
    if (numFromNode == 0 || numFromNode == numToNode) return 1;

    long long &constructionCount = constructionCountCache[numFromNode][numToNode];

    if (constructionCount != UNMEMOIZED) return constructionCount;

    return constructionCount = memoizeConstructionCount(numFromNode - 1, numToNode - 1)
                               + memoizeConstructionCount(numFromNode, numToNode - 1);
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int numFromNode;
        int numToNode;

        cin >> numFromNode >> numToNode;

        memset(constructionCountCache, UNMEMOIZED, sizeof(constructionCountCache));

        cout << memoizeConstructionCount(numFromNode, numToNode) << '\n';
    }

    return 0;
}
