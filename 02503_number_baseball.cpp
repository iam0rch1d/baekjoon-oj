#include <iostream>

using namespace std;

int isImpossible[1000];

int main() {
    int n;
    int candidateCount = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int query;
        int strikes;
        int balls;

        cin >> query >> strikes >> balls;

        int queryDigits[] = {query / 100, query / 10 % 10, query % 10};

        for (int candidate = 123; candidate <= 987; candidate++) {
            int candidateDigits[] = {candidate / 100, candidate / 10 % 10, candidate % 10};

            if (!candidateDigits[0] || !candidateDigits[1] || !candidateDigits[2]
                || candidateDigits[0] == candidateDigits[1]
                || candidateDigits[1] == candidateDigits[2]
                || candidateDigits[2] == candidateDigits[0]) {
                isImpossible[candidate] = true;

                continue;
            }

            int candidateStrikeCount = 0;
            int candidateBallCount = 0;

            for (int j = 0; j < 3; j++) {
                if (candidateDigits[j] == queryDigits[j]) candidateStrikeCount++;
                else if (candidateDigits[(j + 1) % 3] == queryDigits[j]
                         || candidateDigits[(j + 2) % 3] == queryDigits[j]) {
                    candidateBallCount++;
                }
            }

            if (candidateBallCount != balls || candidateStrikeCount != strikes) isImpossible[candidate] = true;
        }
    }

    for (int i = 123; i <= 987; i++) {
        candidateCount += !isImpossible[i];
    }

    cout << candidateCount << '\n';

    return 0;
}
