#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1

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
    int t;

    cin >> t;

    memset(methodCountCache, UNMEMOIZED, sizeof(methodCountCache));

    while (t--) {
        int target;

        cin >> target;
        cout << memoizeMethodCount(target) << '\n';
    }

    return 0;
}
