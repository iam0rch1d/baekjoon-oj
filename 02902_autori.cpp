#include <iostream>

using namespace std;

int main() {
    string s;

    cin >> s;

    for (char sChar : s) {
        if (sChar >= 'A' && sChar <= 'Z') cout << sChar;
    }

    cout << '\n';

    return 0;
}
