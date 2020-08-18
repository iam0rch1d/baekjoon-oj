#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numCoinType;
    int targetValue;
    int indexCoinToMakeUp;
    int numRequiredCoin = 0;

    cin >> numCoinType >> targetValue;

    indexCoinToMakeUp = numCoinType - 1;

    int coinValues[numCoinType];

    for (int &coinValue : coinValues) {
        cin >> coinValue;
    }

    while (targetValue > 0) {
        if (coinValues[indexCoinToMakeUp] <= targetValue) {
            targetValue -= coinValues[indexCoinToMakeUp];
            numRequiredCoin++;
        } else indexCoinToMakeUp--;
    }

    cout << numRequiredCoin << endl;

    return 0;
}
