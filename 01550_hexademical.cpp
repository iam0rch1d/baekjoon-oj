#include <iostream>

using namespace std;

int main() {
    string s;
    int sSize;
    int decimal = 0;

    cin >> s;

    sSize = s.size();

    for (int i = 0; i < sSize; i++) {
        decimal = decimal * 16 + (s[i] >= '0' && s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10);
    }

    cout << decimal << '\n';

    return 0;
}
