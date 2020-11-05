#include <iostream>

using namespace std;

int main() {
    int cost;
    int changeUnits[] = {500, 100, 50, 10, 5, 1};
    int totalChanges = 0;

    cin >> cost;

    cost = 1000 - cost;

    for (int changeUnit : changeUnits) {
        int changes = cost / changeUnit;

        cost -= changes * changeUnit;
        totalChanges += changes;
    }

    cout << totalChanges << '\n';

    return 0;
}
