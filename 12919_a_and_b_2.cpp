#include <algorithm>
#include <iostream>

using namespace std;

string popBack(string s) {
    s.pop_back();

    return s;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());

    return s;
}

bool canMake(const string &from, string to) {
    if (from == to) return true;

    if (!to.empty()) {
        if ((to.back() == 'A' && canMake(from, popBack(to)))
            || (to[0] == 'B' && canMake(from, popBack(reverseString(to)))))
            return true;
    }

    return false;
}

int main() {
    string s;
    string t;

    cin >> s >> t;
    cout << canMake(s, t) << '\n';

    return 0;
}
