#include <iostream>

using namespace std;

int main() {
    string s[5];

    for (auto &si : s) {
        cin >> si;

        si += string(15 - si.size(), ' ');
    }

    for (int i = 0; i < 15; i++) {
        for (auto &sj : s) {
            if (sj[i] != ' ') cout << sj[i];
        }
    }

    cout << '\n';

    return 0;
}
