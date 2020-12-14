#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1
#define MODULO 1000000009

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
    int testcases;

    memset(methodCountCache, UNMEMOIZED, sizeof(methodCountCache));

    cin >> testcases;

    while (testcases--) {
        int target;

        cin >> target;

        cout << memoizeMethodCount(target) << '\n';
    }

    return 0;
}
