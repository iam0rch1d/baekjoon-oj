#include <iostream>

using namespace std;

int main() {
    string buffer;

    while (getline(cin, buffer)) {
        cout << buffer << '\n';
    }

    return 0;
}
