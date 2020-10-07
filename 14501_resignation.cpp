#include <algorithm>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int maxTotalPayCache[16];

int main() {
    int numDay;
    pair<int, int> consultations[15];

    cin >> numDay;

    for (int i = 0; i < numDay; i++) {
        cin >> consultations[i].first >> consultations[i].second;  // .first = <days required>, .second = <pay>

        maxTotalPayCache[i + 1] = max(maxTotalPayCache[i + 1], maxTotalPayCache[i]);

        if (i + consultations[i].first <= numDay) {
            maxTotalPayCache[i + consultations[i].first] = max(maxTotalPayCache[i + consultations[i].first],
                                                               maxTotalPayCache[i] + consultations[i].second);
        }
    }

    cout << *max_element(maxTotalPayCache, maxTotalPayCache + numDay + 1) << '\n';

    return 0;
}
