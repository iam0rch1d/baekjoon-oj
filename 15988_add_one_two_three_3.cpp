#include <cstring>
#include <iostream>

#define UNMEMOIZED -1
#define MODULO 1000000009

using namespace std;

long long methodCountCache[1000001];

long long memoizeMethodCount(int target) {
    if (target <= 2) return target;
    else if (target == 3) return 4;

    long long &methodCount = methodCountCache[target];

    if (methodCount != UNMEMOIZED) return methodCount;

    return methodCount = (memoizeMethodCount(target - 1)
                          + memoizeMethodCount(target - 2)
                          + memoizeMethodCount(target - 3)) % MODULO;
}

int main() {
    int numTestcase;

    memset(methodCountCache, UNMEMOIZED, sizeof(methodCountCache));

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int target;

        cin >> target;

        cout << memoizeMethodCount(target) << '\n';
    }

    return 0;
}
