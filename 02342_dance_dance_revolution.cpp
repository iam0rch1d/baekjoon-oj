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
int dp[100000][5][5];

int memoize(int stepNo, pair<int, int> on) {
    if (stepNo == stepsSize) return 0;

    int &ret = dp[stepNo][on.first][on.second];

    if (ret) return ret;

    ret = 400000;

    if (steps[stepNo] != on.first) {
        ret = min(ret, memoize(stepNo + 1, {on.first, steps[stepNo]}) + energies[on.second][steps[stepNo]]);
    }

    if (steps[stepNo] != on.second) {
        ret = min(ret, memoize(stepNo + 1, {steps[stepNo], on.second}) + energies[on.first][steps[stepNo]]);
    }

    return ret;
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

    cout << memoize(0, {0, 0}) << '\n';

    return 0;
}
