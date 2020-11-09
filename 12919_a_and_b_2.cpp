#include <algorithm>
#include <iostream>

using namespace std;

string popBackString(string s) {
    s.pop_back();

    return s;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());

    return s;
}

bool canMake(const string &from, string to) {
    if (from.size() == to.size()) return from == to;

    return (to.back() == 'A' && canMake(from, popBackString(to)))
           || (to[0] == 'B' && canMake(from, popBackString(reverseString(to))));
}

int main() {
    string s;
    string t;

    cin >> s >> t;
    cout << canMake(s, t) << '\n';

    return 0;
}
