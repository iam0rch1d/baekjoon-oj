#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;

    cin >> tc;

    cin.ignore();

    while (tc--) {
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
            cout << reversedToken << ' ';
        }

        cout << '\n';
    }

    return 0;
}
