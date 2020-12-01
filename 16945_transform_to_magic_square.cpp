#include <iostream>

using namespace std;

int main() {
    int magicSquares[8][9] = {{2, 7, 6, 9, 5, 1, 4, 3, 8},
                              {2, 9, 4, 7, 5, 3, 6, 1, 8},
                              {4, 3, 8, 9, 5, 1, 2, 7, 6},
                              {4, 9, 2, 3, 5, 7, 8, 1, 6},
                              {6, 1, 8, 7, 5, 3, 2, 9, 4},
                              {6, 7, 2, 1, 5, 9, 8, 3, 4},
                              {8, 1, 6, 3, 5, 7, 4, 9, 2},
                              {8, 3, 4, 1, 5, 9, 6, 7, 2}};
    int a[9];
    int minCost = 81;

    for (int &ai : a) {
        cin >> ai;
    }

    for (auto &magicSquare : magicSquares) {
        int cost = 0;

        for (int i = 0; i < 9; i++) {
            cost += abs(magicSquare[i] - a[i]);
        }

        minCost = min(minCost, cost);
    }

    cout << minCost << '\n';

    return 0;
}
