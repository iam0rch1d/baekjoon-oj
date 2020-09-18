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
        string sentence;
        string token;
        vector<string> tokens;

        getline(cin, sentence);

        stringstream tokenizer(sentence);

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
