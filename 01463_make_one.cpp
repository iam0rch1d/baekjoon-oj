#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int operationCountCache[1000001];

int memoizeOperationCount(int x) {
    if (x == 1) return 0;

    int &operationCount = operationCountCache[x];

    if (operationCount != UNKNOWN) return operationCount;

    int whenDividedBy3 = x % 3 == 0 ? 1 + memoizeOperationCount(x / 3) : 1000000;
    int whenDividedBy2 = x % 2 == 0 ? 1 + memoizeOperationCount(x / 2) : 1000000;

    return operationCount = min({1 + memoizeOperationCount(x - 1), whenDividedBy2, whenDividedBy3});
}

int main() {
    int x;

    memset(operationCountCache, UNKNOWN, sizeof(operationCountCache));

    cin >> x;
    cout << memoizeOperationCount(x) << '\n';

    return 0;
}
