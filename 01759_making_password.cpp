#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int length;
    int numChar;

    cin >> length >> numChar;

    vector<char> chars(numChar);
    vector<bool> isCharPicked(numChar, false);
    vector<string> passwords;

    for (char &element : chars) {
        cin >> element;
    }

    for (int i = 0; i < length; i++) {
        isCharPicked[i] = true;
    }

    sort(chars.begin(), chars.end());

    while (true) {
        string password;
        int vowelCount = 0;
        int consonantCount = 0;

        for (int i = 0; i < numChar; i++) {
            if (isCharPicked[i]) {
                password += chars[i];

                if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u') {
                    vowelCount++;
                } else consonantCount++;
            }
        }

        if (vowelCount >= 1 && consonantCount >= 2) passwords.push_back(password);

        if (!prev_permutation(isCharPicked.begin(), isCharPicked.end())) break;
    }

    for (string &password : passwords) {
        cout << password << '\n';
    }

    return 0;
}
