#include <algorithm>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int maximumTotalPayCache[16];

int main() {
    int numDay;
    pair<int, int> consultations[15];

    cin >> numDay;

    for (int i = 0; i < numDay; i++) {
        cin >> consultations[i].first >> consultations[i].second;  // .first = <days required>, .second = <pay>

        maximumTotalPayCache[i + 1] = max(maximumTotalPayCache[i + 1], maximumTotalPayCache[i]);
        maximumTotalPayCache[i + consultations[i].first] = max(maximumTotalPayCache[i + consultations[i].first],
                                                               maximumTotalPayCache[i] + consultations[i].second);
    }

    cout << *max_element(maximumTotalPayCache, maximumTotalPayCache + numDay + 1) << endl;

    return 0;
}
