#include <algorithm>
#include <iostream>
#include <vector>

#define UNMEMOIZED -1

using namespace std;

int memoizeMinimumOperationCount(int number, vector<int> &minimumOperationCountCache) {
    if (minimumOperationCountCache[number] != UNMEMOIZED) return minimumOperationCountCache[number];

    int &minimumOperationCount = minimumOperationCountCache[number];

    if (number == 1) return minimumOperationCount = 0;

    if (number >= 2 && number <= 3) return minimumOperationCount = 1;

    int whenDividedBy3 = number % 3 == 0 ?
                         memoizeMinimumOperationCount(number / 3, minimumOperationCountCache) : INT32_MAX;
    int whenDividedBy2 = number % 2 == 0 ?
                         memoizeMinimumOperationCount(number / 2, minimumOperationCountCache) : INT32_MAX;

    return minimumOperationCount = 1 + min({whenDividedBy3,
                                            whenDividedBy2,
                                            memoizeMinimumOperationCount(number - 1, minimumOperationCountCache)});
}

int main() {
    int number;

    cin >> number;

    vector<int> minimumOperationCountCache(number + 1, UNMEMOIZED);

    cout << memoizeMinimumOperationCount(number, minimumOperationCountCache) << endl;

    return 0;
}
