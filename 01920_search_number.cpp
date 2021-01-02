#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numbersSize;
int numbers[100000];

void binarySearch(pair<int, int> interval, int target) {
    if (interval.first >= interval.second
        || target < numbers[interval.first]
        || target > numbers[interval.second - 1]) {
        cout << "0\n";

        return;
    }

    int mid = (interval.first + interval.second) / 2;

    if (target < numbers[mid]) binarySearch({interval.first, mid}, target);
    else if (target > numbers[mid]) binarySearch({mid, interval.second}, target);
    else {
        cout << "1\n";

        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int targetsSize;

    cin >> numbersSize;

    for (int i = 0; i < numbersSize; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + numbersSize);

    cin >> targetsSize;

    vector<int> targets(targetsSize);

    for (int &target : targets) {
        cin >> target;
    }

    for (int target : targets) {
        binarySearch({0, numbersSize}, target);
    }

    return 0;
}
