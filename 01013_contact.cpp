#include <iostream>
#include <regex>

using namespace std;

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        string s;

        cin >> s;
        cout << (regex_match(s, regex("(100+1+|01)+")) ? "YES\n" : "NO\n");
    }

    return 0;
}
