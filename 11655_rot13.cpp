#include <iostream>

using namespace std;

int main() {
    string s;
    string::iterator head;

    getline(cin, s);

    head = s.begin();

    while (*head != '\0') {
        if (*head >= 'A' && *head <= 'Z') *head = (*head - 'A' + 13) % 26 + 'A';
        else if (*head >= 'a' && *head <= 'z') *head = (*head - 'a' + 13) % 26 + 'a';

        head++;
    }

    cout << s << '\n';

    return 0;
}
