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

    for (int i = 0; i < numConference; i++) {
        cin >> conferences[i].startTime >> conferences[i].endTime;
    }

    sort(conferences.begin(), conferences.end(), [](auto i, auto j) {
        return (i.endTime < j.endTime) || (i.endTime == j.endTime && i.startTime < j.startTime);
    });

    for (int i = 0; i < numConference; i++) {
        if (conferences[i].startTime >= vacantTime) {
            numAvailableConference++;
            vacantTime = conferences[i].endTime;
        }
    }

    cout << numAvailableConference << endl;

    return 0;
}
