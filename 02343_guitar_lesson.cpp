#include <algorithm>
#include <iostream>

using namespace std;

int n;
int m;
int lessonTimes[100000];

bool canRecord(int withBlurayTime) {
    int recordedTime = 0;
    int blurayCount = 1;

    for (int i = 0; i < n; i++) {
        if (recordedTime + lessonTimes[i] <= withBlurayTime) recordedTime += lessonTimes[i];
        else {
            recordedTime = lessonTimes[i];
            blurayCount++;
        }
    }

    return blurayCount <= m;
}

int main() {
    int blurayTimeLeft;
    int blurayTimeRight = 0;
    int blurayTime;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> lessonTimes[i];

        blurayTimeRight += lessonTimes[i];
    }

    blurayTimeLeft = *max_element(lessonTimes, lessonTimes + n);

    while (blurayTimeLeft <= blurayTimeRight) {
        int blurayTimeMid = (blurayTimeLeft + blurayTimeRight) / 2;

        if (canRecord(blurayTimeMid)) {
            blurayTime = blurayTimeMid;
            blurayTimeRight = blurayTimeMid - 1;
        } else blurayTimeLeft = blurayTimeMid + 1;
    }

    cout << blurayTime << '\n';

    return 0;
}
