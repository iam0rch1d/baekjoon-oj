#include <iostream>

using namespace std;

int main() {
    int totalValue;

    cin >> totalValue;

    for (int i = 0; i < 9; i++) {
        int value;

        cin >> value;

        totalValue -= value;
    }

    cout << totalValue << '\n';

    return 0;
}
