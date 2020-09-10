#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numbersSize;
int numbers[100000];

void bisectNumber(pair<int, int> interval, int target) {
    if (interval.first >= interval.second
        || target < numbers[interval.first]
        || target > numbers[interval.second - 1]) {
        cout << "0\n";

        return;
    }

    int center = (interval.first + interval.second) / 2;

    if (target < numbers[center]) bisectNumber({interval.first, center}, target);
    else if (target > numbers[center]) bisectNumber({center, interval.second}, target);
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
        bisectNumber({0, numbersSize}, target);
    }

    return 0;
}
