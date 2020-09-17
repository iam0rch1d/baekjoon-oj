#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numCoinValue;
    int targetValueSum;

    cin >> numCoinValue >> targetValueSum;

    vector<int> methodCountCache(targetValueSum + 1, 0);

    methodCountCache[0] = 1;

    while (numCoinValue-- > 0) {
        int coinValue;

        cin >> coinValue;

        for (int j = coinValue; j <= targetValueSum; j++) {
            methodCountCache[j] += methodCountCache[j - coinValue];
        }
    }

    cout << methodCountCache[targetValueSum] << endl;

    return 0;
}
