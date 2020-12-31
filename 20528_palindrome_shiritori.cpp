#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using vc = vector<char>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int n;

    cin >> n;

    vc palindromes(n);

    REP(i, n) {
        string s;

        cin >> s;

        palindromes[i] = s[0];
    }

    sort(ALL(palindromes));

    bool ans = true;

    FOR(i, 0, n - 1) if (palindromes[i] != palindromes[i + 1]) ans = false;

    PRINTLN(ans);

    return 0;
}
