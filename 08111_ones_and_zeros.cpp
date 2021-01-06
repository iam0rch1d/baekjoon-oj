#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int tc;

    cin >> tc;

    auto solve = []() -> string {
        int n;

        cin >> n;

        vi distances(n, -1);
        vi backRemainders(n, -1);
        vi digits(n, -1);
        queue<int> bfsRemainders;

        distances[1 % n] = 0;
        digits[1 % n] = 1;

        bfsRemainders.push(1 % n);

        while (!bfsRemainders.empty()) {
            int currentRemainder = bfsRemainders.front();

            bfsRemainders.pop();

            REP(i, 2) {
                int adjacentRemainder = (currentRemainder * 10 + i) % n;

                if (distances[adjacentRemainder] == -1) {
                    distances[adjacentRemainder] = distances[currentRemainder] + 1;
                    backRemainders[adjacentRemainder] = currentRemainder;
                    digits[adjacentRemainder] = i;

                    bfsRemainders.push(adjacentRemainder);
                }
            }
        }

        if (distances[0] == -1) return "BRAK";

        string ret;
        int remainder = 0;

        while (remainder != -1) {
            ret += (char) (digits[remainder] + '0');
            remainder = backRemainders[remainder];
        }

        reverse(ALL(ret));

        return ret;
    };

    while (tc--) PRINTLN(solve());

    return 0;
}
