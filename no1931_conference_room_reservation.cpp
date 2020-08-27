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
    int numAvailableConference = 0;

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
            numAvailableConference++;
            vacantTime = conference.endTime;
        }
    }

    cout << numAvailableConference << endl;

    return 0;
}
