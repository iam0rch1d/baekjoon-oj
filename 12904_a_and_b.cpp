#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s;
    string t;
    int sSize;
    int tSize;

    cin >> s >> t;

    sSize = s.size();
    tSize = t.size();

    while (sSize < tSize) {
        char tBack = t.back();

        t.pop_back();

        if (tBack == 'B') reverse(t.begin(), t.end());

        tSize--;

        if (sSize == tSize) {
            cout << (s == t) << '\n';

            return 0;
        }
    }
}
