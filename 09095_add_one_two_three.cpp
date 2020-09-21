#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int methodCountCache[11];

int memoizeMethodCount(int target) {
    if (target <= 2) return target;
    else if (target == 3) return 4;

    int &methodCount = methodCountCache[target];

    if (methodCount != UNMEMOIZED) return methodCount;

    return methodCount = memoizeMethodCount(target - 1)
                         + memoizeMethodCount(target - 2)
                         + memoizeMethodCount(target - 3);
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    memset(methodCountCache, UNMEMOIZED, sizeof(methodCountCache));

    while (numTestcase-- > 0) {
        int target;

        cin >> target;

        cout << memoizeMethodCount(target) << endl;
    }

    return 0;
}
