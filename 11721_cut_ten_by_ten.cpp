#include <iostream>

using namespace std;

int main() {
    string word;

    cin >> word;

    for (int i = 0; i < word.size(); i += 10) {
        cout << word.substr(i, 10) << '\n';
    }

    return 0;
}
