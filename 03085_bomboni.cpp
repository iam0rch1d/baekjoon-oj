#include <iostream>
#include <vector>

using namespace std;

int candyGridSize;
vector<string> candies;

int calculateMaxEatableCandies() {
    int eatableCandies;
    int maxEatableCandies = 1;

    for (int i = 0; i < candyGridSize; i++) {
        eatableCandies = 1;

        for (int j = 1; j < candyGridSize; j++) {
            if (candies[i][j] == candies[i][j - 1]) maxEatableCandies = max(maxEatableCandies, ++eatableCandies);
            else eatableCandies = 1;
        }

        eatableCandies = 1;

        for (int j = 1; j < candyGridSize; j++) {
            if (candies[j][i] == candies[j - 1][i]) maxEatableCandies = max(maxEatableCandies, ++eatableCandies);
            else eatableCandies = 1;
        }
    }

    return maxEatableCandies;
}

int main() {
    int maxEatableCandies = 0;

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

                maxEatableCandies = max(maxEatableCandies, calculateMaxEatableCandies());

                swap(candies[i][j], candies[i + 1][j]);
            }

            if (j < candyGridSize - 1) {
                swap(candies[i][j], candies[i][j + 1]);

                maxEatableCandies = max(maxEatableCandies, calculateMaxEatableCandies());

                swap(candies[i][j], candies[i][j + 1]);
            }
        }
    }

    cout << maxEatableCandies << '\n';

    return 0;
}
