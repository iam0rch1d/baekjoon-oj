#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    string t;
    string p;

    getline(cin, t);
    getline(cin, p);

    int m = p.size();
    vi failures(m);

    failures[0] = 0;

    int prefixIndex = 0;

    FOR(i, 1, m) {
        while (prefixIndex && p[i] != p[prefixIndex]) {
            prefixIndex = failures[prefixIndex - 1];
        }

        if (p[i] == p[prefixIndex]) failures[i] = ++prefixIndex;
        else prefixIndex = 0;
    }

    int n = t.size();
    vector<int> hits;

    prefixIndex = 0;

    FOR(i, 0, n) {
        while (prefixIndex && t[i] != p[prefixIndex]) {
            prefixIndex = failures[prefixIndex - 1];
        }

        if (t[i] == p[prefixIndex]) {
            if (prefixIndex == m - 1) {
                hits.push_back(i - prefixIndex);

                prefixIndex = failures[prefixIndex];
            } else ++prefixIndex;
        }
    }

    PRINTLN(hits.size());

    for (int hit : hits) PRINTLN(hit + 1);

    return 0;
}
