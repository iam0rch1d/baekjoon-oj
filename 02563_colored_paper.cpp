#include <iostream>

using namespace std;

bool isCovered[101][101];

int main() {
    int n;
    int coveredArea = 0;

    cin >> n;

    while (n--) {
        int y;
        int x;

        cin >> y >> x;

        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                isCovered[i][j] = true;
            }
        }
    }

    for (auto &isCoveredRow : isCovered) {
        for (bool isCoveredElement : isCoveredRow) {
            coveredArea += isCoveredElement;
        }
    }

    cout << coveredArea << '\n';

    return 0;
}
