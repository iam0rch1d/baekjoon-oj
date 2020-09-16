#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Conference {
    int startTime;
    int endTime;
} Conference;

int main() {
    int numConference;
    int vacantTime = 0;
    int availableConferenceCount = 0;

    cin >> numConference;

    vector<Conference> conferences(numConference);

    for (auto &conference : conferences) {
        cin >> conference.startTime >> conference.endTime;
    }

    sort(conferences.begin(), conferences.end(), [](auto i, auto j) {
        return (i.endTime < j.endTime) || (i.endTime == j.endTime && i.startTime < j.startTime);
    });

    for (auto &conference : conferences) {
        if (conference.startTime >= vacantTime) {
            availableConferenceCount++;
            vacantTime = conference.endTime;
        }
    }

    cout << availableConferenceCount << endl;

    return 0;
}
