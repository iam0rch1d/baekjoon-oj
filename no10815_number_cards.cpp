#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int keysSize;
int keys[500000];

void bisectNumber(pair<int, int> interval, int target) {
    if (interval.first >= interval.second
        || target < keys[interval.first]
        || target > keys[interval.second - 1]) {
        cout << "0 ";

        return;
    }

    int center = (interval.first + interval.second) / 2;

    if (target < keys[center]) bisectNumber({interval.first, center}, target);
    else if (target > keys[center]) bisectNumber({center, interval.second}, target);
    else {
        cout << "1 ";

        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int targetsSize;

    cin >> keysSize;

    for (int i = 0; i < keysSize; i++) {
        cin >> keys[i];
    }

    sort(keys, keys + keysSize);

    cin >> targetsSize;

    vector<int> targets(targetsSize);

    for (int &target : targets) {
        cin >> target;
    }

    for (int target : targets) {
        bisectNumber({0, keysSize}, target);
    }

    cout << "\n";

    return 0;
}
