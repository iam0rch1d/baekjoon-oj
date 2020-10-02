#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numPerson;
    int totalTime = 0;

    cin >> numPerson;

    vector<int> withdrawalTimes(numPerson);

    for (int &withdrawalTime : withdrawalTimes) {
        cin >> withdrawalTime;
    }

    sort(withdrawalTimes.begin(), withdrawalTimes.end());

    for (int i = 0; i < numPerson; i++) {
        totalTime += (numPerson - i) * withdrawalTimes[i];
    }

    cout << totalTime << '\n';

    return 0;
}
