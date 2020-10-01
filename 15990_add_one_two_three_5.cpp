#include <cstring>
#include <iostream>

#define UNMEMOIZED -1
#define MODULO 1000000009

using namespace std;

long long methodCountCache[100001][4];

long long memoizeMethodCount(int target, int withFirstNumber) {
    switch (target) {
        case 1: return withFirstNumber == 1 ? 1 : 0;
        case 2: return withFirstNumber == 2 ? 1 : 0;
        case 3: return 1;  // 1 -> {1, 2}, 2 -> {2, 1}, 3 -> {3}
        default: break;
    }

    long long &methodCount = methodCountCache[target][withFirstNumber];

    if (methodCount != UNMEMOIZED) return methodCount;

    switch (withFirstNumber) {
        case 1: return methodCount = memoizeMethodCount(target - 1, 2) + memoizeMethodCount(target - 1, 3) % MODULO;
        case 2: return methodCount = memoizeMethodCount(target - 2, 1) + memoizeMethodCount(target - 2, 3) % MODULO;
        case 3: return methodCount = memoizeMethodCount(target - 3, 1) + memoizeMethodCount(target - 3, 2) % MODULO;
        default: return methodCount = 0;
    }
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    memset(methodCountCache, UNMEMOIZED, sizeof(methodCountCache));

    while (numTestcase-- > 0) {
        int target;

        cin >> target;

        cout << (memoizeMethodCount(target, 1)
                 + memoizeMethodCount(target, 2)
                 + memoizeMethodCount(target, 3)) % MODULO << endl;
    }

    return 0;
}
