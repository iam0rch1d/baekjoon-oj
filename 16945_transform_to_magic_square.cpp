#include <iostream>

using namespace std;

int main() {
    string magicSquares[] = {"276951438",
                             "294753618",
                             "438951276",
                             "492357816",
                             "618753294",
                             "672159834",
                             "816357492",
                             "834159672"};
    int a[9];
    int minCost = 81;

    for (int &ai : a) {
        cin >> ai;
    }

    for (auto &magicSquare : magicSquares) {
        int cost = 0;

        for (int i = 0; i < 9; i++) {
            cost += abs(magicSquare[i] - '0' - a[i]);
        }

        minCost = min(minCost, cost);
    }

    cout << minCost << '\n';

    return 0;
}
