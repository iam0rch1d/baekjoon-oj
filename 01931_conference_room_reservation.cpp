#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int vacantTime = 0;
    int availableConferenceCount = 0;

    cin >> n;

    vector<pair<int, int>> conferences(n);

    for (auto &conference : conferences) {
        cin >> conference.first >> conference.second;
    }

    sort(conferences.begin(), conferences.end(), [](auto i, auto j) {
        return (i.second < j.second) || (i.second == j.second && i.first < j.first);
    });

    for (auto &conference : conferences) {
        if (conference.first >= vacantTime) {
            availableConferenceCount++;
            vacantTime = conference.second;
        }
    }

    cout << availableConferenceCount << '\n';

    return 0;
}
