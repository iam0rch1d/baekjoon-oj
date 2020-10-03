#include <iostream>
#include <vector>

using namespace std;

int candyGridSize;
vector<string> candies;

int calculateMaxEatableCandyCount() {
    int eatableCandyCount;
    int maxEatableCandyCount = 1;

    for (int i = 0; i < candyGridSize; i++) {
        eatableCandyCount = 1;

        for (int j = 1; j < candyGridSize; j++) {
            if (candies[i][j] == candies[i][j - 1]) {
                maxEatableCandyCount = max(maxEatableCandyCount, ++eatableCandyCount);
            } else eatableCandyCount = 1;
        }

        eatableCandyCount = 1;

        for (int j = 1; j < candyGridSize; j++) {
            if (candies[j][i] == candies[j - 1][i]) {
                maxEatableCandyCount = max(maxEatableCandyCount, ++eatableCandyCount);
            } else eatableCandyCount = 1;
        }
    }

    return maxEatableCandyCount;
}

int main() {
    int maxEatableCandyCount = 0;

    cin >> candyGridSize;

    for (int i = 0; i < candyGridSize; i++) {
        string candyRow;

        cin >> candyRow;

        candies.push_back(candyRow);
    }

    for (int i = 0; i < candyGridSize; i++) {
        for (int j = 0; j < candyGridSize; j++) {
            if (i < candyGridSize - 1) {
                swap(candies[i][j], candies[i + 1][j]);

                maxEatableCandyCount = max(maxEatableCandyCount, calculateMaxEatableCandyCount());

                swap(candies[i][j], candies[i + 1][j]);
            }

            if (j < candyGridSize - 1) {
                swap(candies[i][j], candies[i][j + 1]);

                maxEatableCandyCount = max(maxEatableCandyCount, calculateMaxEatableCandyCount());

                swap(candies[i][j], candies[i][j + 1]);
            }
        }
    }

    cout << maxEatableCandyCount << '\n';

    return 0;
}
