#include <algorithm>
#include <iostream>

using namespace std;

long long m;
long long durations[10000];

long long calculateRiders(long long untilTime) {
    if (untilTime == -1) return 0;

    long long riders = m;

    for (int i = 0; i < m; i++) {
        riders += untilTime / durations[i];
    }

    return riders;
}

int main() {
    long long n;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> durations[i];
    }

    long long lastTimeLeft = 0;
    long long lastTimeRight;
    long long lastTime;
    long long riders;

    lastTimeRight = n * m * *max_element(durations, durations + m);

    while (lastTimeLeft <= lastTimeRight) {
        long long lastTimeMid = (lastTimeLeft + lastTimeRight) / 2;

        if (calculateRiders(lastTimeMid) < n) lastTimeLeft = lastTimeMid + 1;
        else {
            lastTime = lastTimeMid;
            lastTimeRight = lastTimeMid - 1;
        }
    }

    riders = calculateRiders(lastTime - 1);

    for (int i = 0; i < m; i++) {
        if (lastTime % durations[i] == 0 && ++riders == n) {
            cout << i + 1 << '\n';

            return 0;
        }
    }
}
