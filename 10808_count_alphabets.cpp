#include <iostream>

using namespace std;

int alphabetCounts[26];

int main() {
    string s;
    string::iterator head;

    cin >> s;

    head = s.begin();

    while (*head != '\0') {
        alphabetCounts[*head - 'a']++;

        head++;
    }

    for (int alphabetCount : alphabetCounts) {
        cout << alphabetCount << ' ';
    }

    cout << '\n';

    return 0;
}
