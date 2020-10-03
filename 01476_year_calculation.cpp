#include <iostream>
#include <tuple>

using namespace std;

int main() {
    tuple<int, int, int> target;
    tuple<int, int, int> counter{1, 1, 1};
    int year = 1;

    cin >> get<0>(target) >> get<1>(target) >> get<2>(target);

    while (!(target == counter)) {
        get<0>(counter) = get<0>(counter) % 15 + 1;
        get<1>(counter) = get<1>(counter) % 28 + 1;
        get<2>(counter) = get<2>(counter) % 19 + 1;
        year++;
    }

    cout << year << '\n';

    return 0;
}
