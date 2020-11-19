#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int callSum = 0;
    int m;

    cin >> n;

    vector<int> calls(n);

    for (int &call : calls) {
        cin >> call;

        callSum += call;
    }

    cin >> m;

    if (callSum <= m) {
        cout << *max_element(calls.begin(), calls.end());

        return 0;
    }

    if (*min_element(calls.begin(), calls.end()) * n > m) {
        cout << m / n << '\n';

        return 0;
    }

    int limitLeft = *min_element(calls.begin(), calls.end());
    int limitRight = *max_element(calls.begin(), calls.end());
    int limit;

    while (limitLeft <= limitRight) {
        int limitMid = (limitLeft + limitRight) / 2;
        int allocatedBudgetSum = 0;

        for (int call : calls) {
            allocatedBudgetSum += min(call, limitMid);
        }

        if (allocatedBudgetSum <= m) {
            limit = limitMid;
            limitLeft = limitMid + 1;
        } else limitRight = limitMid - 1;
    }

    cout << limit << '\n';

    return 0;
}
