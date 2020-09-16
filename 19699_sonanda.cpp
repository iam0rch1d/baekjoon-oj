#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numCow;
int numToSelectCow;
int cowWeights[9];
int primeCache[] = {2, 3, 5, 7, 11,
                    13, 17, 19, 23, 29,
                    31, 37, 41, 43, 47,
                    53, 59, 61, 67, 71,
                    73, 79, 83, 89};
vector<int> primeCowWeightSums;

void backtrackCowWeightSum(vector<int> &selectedCowWeights, int lastSelectedCowNo) {
    if (selectedCowWeights.size() == numToSelectCow) {
        int isPrime = true;
        int selectedCowWeightSum = 0;

        for (int selectedCowWeight : selectedCowWeights) {
            selectedCowWeightSum += selectedCowWeight;
        }

        for (int i = 0; primeCache[i] * primeCache[i] <= selectedCowWeightSum; i++) {
            if (selectedCowWeightSum % primeCache[i] == 0) {
                isPrime = false;

                break;
            }
        }

        if (isPrime) primeCowWeightSums.push_back(selectedCowWeightSum);

        return;
    }

    for (int i = 1; lastSelectedCowNo + i < numCow; i++) {
        selectedCowWeights.push_back(cowWeights[lastSelectedCowNo + i]);

        backtrackCowWeightSum(selectedCowWeights, lastSelectedCowNo + i);

        selectedCowWeights.pop_back();
    }
}

int main() {
    vector<int> selectedCowWeights;

    cin >> numCow >> numToSelectCow;

    for (int i = 0; i < numCow; i++) {
        cin >> cowWeights[i];
    }

    backtrackCowWeightSum(selectedCowWeights, -1);

    if (primeCowWeightSums.empty()) {
        cout << "-1" << endl;
    } else {
        sort(primeCowWeightSums.begin(), primeCowWeightSums.end());

        for (int i = 0; i < primeCowWeightSums.size(); i++) {
            if (i == 0 || primeCowWeightSums[i] != primeCowWeightSums[i - 1]) cout << primeCowWeightSums[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
