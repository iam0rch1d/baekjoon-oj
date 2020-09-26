#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string baseN;
    int base;
    long long decimal = 0;
    long long place = 1;

    cin >> baseN >> base;

    reverse(baseN.begin(), baseN.end());

    for (char baseNChar : baseN) {
        decimal += (baseNChar >= '0' && baseNChar <= '9' ? baseNChar - '0' : baseNChar - 'A' + 10) * place;
        place *= base;
    }

    cout << decimal << '\n';

    return 0;
}
