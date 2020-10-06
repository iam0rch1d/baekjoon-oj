#include <iostream>

using namespace std;

int main() {
    string buffer;

    while (getline(cin, buffer)) {
        string::iterator head = buffer.begin();
        int lowercaseCount = 0;
        int uppercaseCount = 0;
        int digitCount = 0;
        int spaceCount = 0;

        while (*head != '\0') {
            if (*head >= 'a' && *head <= 'z') lowercaseCount++;
            else if (*head >= 'A' && *head <= 'Z') uppercaseCount++;
            else if (*head >= '0' && *head <= '9') digitCount++;
            else spaceCount++;

            head++;
        }

        cout << lowercaseCount << ' ' << uppercaseCount << ' ' << digitCount << ' ' << spaceCount << '\n';
    }

    return 0;
}
