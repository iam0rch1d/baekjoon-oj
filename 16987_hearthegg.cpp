#include <iostream>

using namespace std;

int n;
int s[8];
int w[8];

int backtrackBeatEgg(int pickedEgg) {
    if (pickedEgg == n) {
        int breakCount = 0;

        for (int i = 0; i < n; i++) {
            breakCount += s[i] <= 0;
        }

        return breakCount;
    }

    if (s[pickedEgg] <= 0) return backtrackBeatEgg(pickedEgg + 1);

    bool canBeat = false;
    int maxBreakCount = 0;

    for (int i = 0; i < n; i++) {
        if (i == pickedEgg || s[i] <= 0) continue;

        canBeat = true;
        s[pickedEgg] -= w[i];
        s[i] -= w[pickedEgg];
        maxBreakCount = max(maxBreakCount, backtrackBeatEgg(pickedEgg + 1));
        s[pickedEgg] += w[i];
        s[i] += w[pickedEgg];
    }

    if (!canBeat) return backtrackBeatEgg(pickedEgg + 1);

    return maxBreakCount;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }

    cout << backtrackBeatEgg(0) << '\n';

    return 0;
}
