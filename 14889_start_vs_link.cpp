#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numPerson;
    int minTotalSynergyDifference = 1e4;

    cin >> numPerson;

    vector<vector<int>> synergies(numPerson, vector<int>(numPerson));
    vector<bool> isInStart(numPerson, false);

    for (int i = 0; i < numPerson; i++) {
        for (int j = 0; j < numPerson; j++){
            cin >> synergies[i][j];
        }
    }

    for (int i = 0; i < numPerson / 2; i++) {
        isInStart[i] = true;
    }

    while (true) {
        int startTotalSynergy = 0;
        int linkTotalSynergy = 0;

        for (int i = 0; i < numPerson; i++) {
            for (int j = 0; j < numPerson; j++) {
                if (isInStart[i] && isInStart[j]) startTotalSynergy += synergies[i][j];
                else if (!isInStart[i] && !isInStart[j]) linkTotalSynergy += synergies[i][j];
            }
        }

        minTotalSynergyDifference = min(minTotalSynergyDifference, abs(startTotalSynergy - linkTotalSynergy));

        if (!prev_permutation(isInStart.begin(), isInStart.end())) break;
    }

    cout << minTotalSynergyDifference << '\n';

    return 0;
}
