#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        pair<int, int> doomsday;
        pair<int, int> current;
        int year;
        bool isFailed = false;

        cin >> doomsday.first >> doomsday.second >> current.first >> current.second;

        year = current.first - 1;

        while (year % doomsday.second != current.second - 1) {
            year += doomsday.first;

            if (year > doomsday.first * doomsday.second / __gcd(doomsday.first, doomsday.second)) {
                isFailed = true;

                break;
            }
        }

        cout << (isFailed ? -1 : year + 1) << '\n';
    }

    return 0;
}
