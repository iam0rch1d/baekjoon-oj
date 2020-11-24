#include <iostream>

using namespace std;

int main() {
    string s;
    int sSize;
    int licensePlates;

    cin >> s;

    sSize = s.size();
    licensePlates = s[0] == 'c' ? 26 : 10;

    for (int i = 1; i < sSize; i++) {
        licensePlates *= (s[i] == 'c' ? 26 : 10) - (s[i] == s[i - 1]);
    }

    cout << licensePlates << '\n';

    return 0;
}
