#include <iostream>
#include <regex>

using namespace std;

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        string s;

        cin >> s;
        cout << (regex_match(s, regex("(100+1+|01)+")) ? "YES\n" : "NO\n");
    }

    return 0;
}
