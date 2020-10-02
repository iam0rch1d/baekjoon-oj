#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> steps;
int stepsSize;
int energies[5][5] = {{0, 2, 2, 2, 2},
                      {0, 1, 3, 4, 3},
                      {0, 3, 1, 3, 4},
                      {0, 4, 3, 1, 3},
                      {0, 3, 4, 3, 1}};
int minTotalEnergyCache[100000][5][5];

int memoizeMinTotalEnergy(int currentStepNo, pair<int, int> steppedOn) {
    if (currentStepNo == stepsSize) return 0;

    int &minTotalEnergy = minTotalEnergyCache[currentStepNo][steppedOn.first][steppedOn.second];

    if (minTotalEnergy) return minTotalEnergy;

    minTotalEnergy = 400000;

    if (steps[currentStepNo] != steppedOn.first) {
        minTotalEnergy = min(minTotalEnergy,
                             memoizeMinTotalEnergy(currentStepNo + 1, {steppedOn.first, steps[currentStepNo]})
                             + energies[steppedOn.second][steps[currentStepNo]]);
    }

    if (steps[currentStepNo] != steppedOn.second) {
        minTotalEnergy = min(minTotalEnergy,
                             memoizeMinTotalEnergy(currentStepNo + 1, {steps[currentStepNo], steppedOn.second})
                             + energies[steppedOn.first][steps[currentStepNo]]);
    }

    return minTotalEnergy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int step;

    while (true) {
        cin >> step;

        if (step == 0) break;

        steps.push_back(step);
    }

    stepsSize = steps.size();

    cout << memoizeMinTotalEnergy(0, {0, 0}) << '\n';

    return 0;
}
