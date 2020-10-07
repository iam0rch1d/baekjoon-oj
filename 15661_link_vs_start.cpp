#include <iostream>

using namespace std;

int numPerson;
int synergies[20][20];
int isInStart[20];
int minTotalSynergyDifference = 1e4;

void backtrackTotalSynergyDifference(int toDraftIndex) {
    if (toDraftIndex >= numPerson) {
        int startTotalSynergy = 0;
        int linkTotalSynergy = 0;
        int totalSynergyDifference;

        for (int i = 0; i < numPerson; i++) {
            for (int j = 0; j < numPerson; j++) {
                if (isInStart[i] && isInStart[j]) startTotalSynergy += synergies[i][j];
                else if (!isInStart[i] && !isInStart[j]) linkTotalSynergy += synergies[i][j];
            }
        }

        if ((totalSynergyDifference = abs(startTotalSynergy - linkTotalSynergy)) == 0) {
            cout << "0\n";

            exit(0);
        }

        minTotalSynergyDifference = min(minTotalSynergyDifference, totalSynergyDifference);

        return;
    }

    isInStart[toDraftIndex] = true;

    backtrackTotalSynergyDifference(toDraftIndex + 1);

    isInStart[toDraftIndex] = false;

    backtrackTotalSynergyDifference(toDraftIndex + 1);
}

int main() {
    cin >> numPerson;

    for (int i = 0; i < numPerson; i++) {
        for (int j = 0; j < numPerson; j++) {
            cin >> synergies[i][j];
        }
    }

    backtrackTotalSynergyDifference(0);

    cout << minTotalSynergyDifference << '\n';

    return 0;
}
