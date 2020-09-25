#include <iostream>

using namespace std;

int main() {
    string numbers[4];
    string concatenated[2];

    for (int i = 0; i < 4; i++) {
        cin >> numbers[i];

        concatenated[i / 2] += numbers[i];
    }

    cout << stoll(concatenated[0]) + stoll(concatenated[1]) << '\n';

    return 0;
}
