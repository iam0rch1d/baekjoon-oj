#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numCall;
    vector<int> moneyStack;
    int totalMoney = 0;

    cin >> numCall;

    while (numCall-- > 0) {
        int calledMoney;

        cin >> calledMoney;

        if (calledMoney != 0) moneyStack.push_back(calledMoney);
        else moneyStack.pop_back();
    }

    for (int &money : moneyStack) {
        totalMoney += money;
    }

    cout << totalMoney << '\n';

    return 0;
}
