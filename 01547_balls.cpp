#include <iostream>

using namespace std;

int main() {
    int m;
    int cups[]{0, 1, 0, 0};

    cin >> m;

    while (m--) {
        int x;
        int y;

        cin >> x >> y;

        swap(cups[x], cups[y]);
    }

    for (int i = 1; i <= 3; i++) {
        if (cups[i]) cout << i << '\n';
    }

    return 0;
}
