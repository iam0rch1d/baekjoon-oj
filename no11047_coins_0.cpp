#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int numCoinType;
    int targetValue;
    int toMakeUpCoinNo;
    int numRequiredCoin = 0;

    cin >> numCoinType >> targetValue;

    toMakeUpCoinNo = numCoinType - 1;

    int coinValues[numCoinType];

    for (int &coinValue : coinValues) {
        cin >> coinValue;
    }

    while (targetValue > 0) {
        if (coinValues[toMakeUpCoinNo] <= targetValue) {
            targetValue -= coinValues[toMakeUpCoinNo];
            numRequiredCoin++;
        } else toMakeUpCoinNo--;
    }

    cout << numRequiredCoin << endl;

    return 0;
}
