#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

bool isSubmitted[31];

int main() {
    REP(i, 28) {
        int a;

        cin >> a;

        isSubmitted[a] = true;
    }

    FOR_(i, 1, 30) if (!isSubmitted[i]) PRINTLN(i);

    return 0;
}
