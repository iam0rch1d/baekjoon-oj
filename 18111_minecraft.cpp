#include <iostream>

using namespace std;

int main() {
    int numRow;
    int numColumn;
    int inventoryBlockCount;
    int totalBlockCount;
    int blockHeights[500][500];
    int leveledHeightLeft = 257;
    int leveledHeightRight;
    int minLevelingTime = 128000000;
    int maxLeveledHeight;

    cin >> numRow >> numColumn >> inventoryBlockCount;

    totalBlockCount = inventoryBlockCount;

    for (int i = 0; i < numRow; i++) {
        for (int j = 0; j < numColumn; j++) {
            cin >> blockHeights[i][j];

            leveledHeightLeft = min(leveledHeightLeft, blockHeights[i][j]);
            totalBlockCount += blockHeights[i][j];
        }
    }

    leveledHeightRight = totalBlockCount / numRow / numColumn;

    for (int leveledHeight = leveledHeightLeft; leveledHeight <= leveledHeightRight; leveledHeight++) {
        int levelingTime = 0;

        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numColumn; j++) {
                levelingTime += (blockHeights[i][j] > leveledHeight ? 2 : 1) * abs(leveledHeight - blockHeights[i][j]);
            }
        }

        if (levelingTime <= minLevelingTime) {
            minLevelingTime = levelingTime;
            maxLeveledHeight = leveledHeight;
        }
    }

    cout << minLevelingTime << ' ' << maxLeveledHeight << '\n';

    return 0;
}
