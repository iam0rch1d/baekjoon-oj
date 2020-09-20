#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int numTestcase;

    cin >> numTestcase;

    cin.ignore();

    while (numTestcase-- > 0) {
        string s;
        string token;
        vector<string> tokens;

        getline(cin, s);

        stringstream tokenizer(s);

        while (getline(tokenizer, token, ' ')) {
            reverse(token.begin(), token.end());

            tokens.push_back(token);
        }

        for (auto &reversedToken : tokens) {
            cout << reversedToken << " ";
        }

        cout << endl;
    }

    return 0;
}
