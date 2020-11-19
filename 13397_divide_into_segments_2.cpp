#include <algorithm>
#include <iostream>

using namespace std;

int n;
int m;
int a[5000];

bool canDivide(int withScore) {
    int segmentBeginIndex = 0;
    int segmentCount = 1;

    for (int i = 1; i < n; i++) {
        int score = *max_element(a + segmentBeginIndex, a + i + 1) - *min_element(a + segmentBeginIndex, a + i + 1);

        if (score > withScore) {
            segmentBeginIndex = i;
            segmentCount++;
        }
    }

    return segmentCount <= m;
}

int main() {
    int scoreLeft = 0;
    int scoreRight;
    int score;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    scoreRight = *max_element(a, a + n) - *min_element(a, a + n);

    while (scoreLeft <= scoreRight) {
        int scoreMid = (scoreLeft + scoreRight) / 2;

        if (canDivide(scoreMid)) {
            score = scoreMid;
            scoreRight = scoreMid - 1;
        } else scoreLeft = scoreMid + 1;
    }

    cout << score << '\n';

    return 0;
}
