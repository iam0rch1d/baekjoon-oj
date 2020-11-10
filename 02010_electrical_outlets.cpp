#include <iostream>

using namespace std;

int main() {
    int n;
    int plug;
    int computers = 0;

    cin >> n >> plug;

    computers += plug;
    n--;

    while (n--) {
        cin >> plug;

        computers += plug - 1;
    }

    cout << computers << '\n';

    return 0;
}
