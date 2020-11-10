#include <iostream>

using namespace std;

int main() {
    string s;
    int sSize;

    cin >> s;

    sSize = s.size();

    for (int i = 0; i + i < sSize; i++) {
        if (s[i] != s[sSize - 1 - i]) {
            cout << "0\n";

            return 0;
        }
    }

    cout << "1\n";

    return 0;
}
