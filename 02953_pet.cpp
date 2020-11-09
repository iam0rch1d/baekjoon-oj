#include <algorithm>
#include <iostream>

using namespace std;

int totalScores[5];

int main() {
    for (int &totalScore : totalScores) {
        for (int j = 0; j < 4; j++) {
            int score;

            cin >> score;

            totalScore += score;
        }
    }

    auto maxTotalScoreElement = max_element(totalScores, totalScores + 5);

    cout << maxTotalScoreElement - totalScores + 1 << ' ' << *maxTotalScoreElement << '\n';

    return 0;
}
