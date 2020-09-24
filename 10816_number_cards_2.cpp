#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> deck;

void bisectNumber(pair<int, int> interval, int target) {
    if (interval.first >= interval.second
        || target < deck[interval.first].first
        || target > deck[interval.second - 1].first) {
        cout << "0 ";

        return;
    }

    int center = (interval.first + interval.second) / 2;

    if (target < deck[center].first) bisectNumber({interval.first, center}, target);
    else if (target > deck[center].first) bisectNumber({center, interval.second}, target);
    else {
        cout << deck[center].second << ' ';

        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int keysSize;
    int keys[500000];
    int targetsSize;

    cin >> keysSize;

    for (int i = 0; i < keysSize; i++) {
        cin >> keys[i];
    }

    sort(keys, keys + keysSize);

    deck.emplace_back(keys[0], 1);

    for (int i = 1; i < keysSize; i++) {
        if (keys[i] == keys[i - 1]) deck.back().second++;
        else deck.emplace_back(keys[i], 1);
    }

    cin >> targetsSize;

    vector<int> targets(targetsSize);

    for (int &target : targets) {
        cin >> target;
    }

    for (int target : targets) {
        bisectNumber({0, deck.size()}, target);
    }

    cout << '\n';

    return 0;
}
