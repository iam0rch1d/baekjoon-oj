#include <iostream>

using namespace std;

int main() {
    int numRow;
    int numColumn;
    int inventoryBlockCount;
    int totalBlockCount;
    int blockHeights[500][500];
    int leveledHeightLow = 257;
    int leveledHeightHigh;
    int minLevelingTime = 128000000;
    int maxLeveledHeight;

    cin >> numRow >> numColumn >> inventoryBlockCount;

    totalBlockCount = inventoryBlockCount;

    for (int i = 0; i < numRow; i++) {
        for (int j = 0; j < numColumn; j++) {
            cin >> blockHeights[i][j];

            leveledHeightLow = min(leveledHeightLow, blockHeights[i][j]);
            totalBlockCount += blockHeights[i][j];
        }
    }

    leveledHeightHigh = totalBlockCount / numRow / numColumn;

    for (int leveledHeight = leveledHeightLow; leveledHeight <= leveledHeightHigh; leveledHeight++) {
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
