#include <iostream>
#include <regex>

using namespace std;

int main() {
    int testcases;

    cin >> testcases;

    while (testcases--) {
        string s;

        cin >> s;
        cout << (regex_match(s, regex("(100+1+|01)+")) ? "YES\n" : "NO\n");
    }

    return 0;
}
