#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int candyGridSize;
vector<string> candies;

int calculateRowMaxEatableCandyCount(int row) {
    int rowEatableCandyCount = 1;
    int maxRowEatableCandyCount = 1;

    for (int i = 1; i < candyGridSize; i++) {
        if (candies[row][i] == candies[row][i - 1]) {
            maxRowEatableCandyCount = max(maxRowEatableCandyCount, ++rowEatableCandyCount);
        } else rowEatableCandyCount = 1;
    }

    return maxRowEatableCandyCount;
}

int calculateColumnMaxEatableCandyCount(int column) {
    int columnEatableCandyCount = 1;
    int maxColumnEatableCandyCount = 1;

    for (int i = 1; i < candyGridSize; i++) {
        if (candies[i][column] == candies[i - 1][column]) {
            maxColumnEatableCandyCount = max(maxColumnEatableCandyCount, ++columnEatableCandyCount);
        } else columnEatableCandyCount = 1;
    }

    return maxColumnEatableCandyCount;
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

                maxEatableCandyCount = max({maxEatableCandyCount,
                                            calculateRowMaxEatableCandyCount(i),
                                            calculateRowMaxEatableCandyCount(i + 1),
                                            calculateColumnMaxEatableCandyCount(j)});

                swap(candies[i][j], candies[i + 1][j]);
            }

            if (j < candyGridSize - 1) {
                swap(candies[i][j], candies[i][j + 1]);

                maxEatableCandyCount = max({maxEatableCandyCount,
                                            calculateRowMaxEatableCandyCount(i),
                                            calculateColumnMaxEatableCandyCount(j),
                                            calculateColumnMaxEatableCandyCount(j + 1)});

                swap(candies[i][j], candies[i][j + 1]);
            }
        }
    }

    cout << maxEatableCandyCount << '\n';

    return 0;
}
