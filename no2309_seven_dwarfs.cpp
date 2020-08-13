#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void performHeightDfs(const int heights[9], bool isDwarfPicked[9], vector<int> pickedHeights) {
    int numPickedDwarf = 0;
    int pickedHeightSum = 0;
    int lastPickedDwarfNo = -1;

    for (int i = 0; i < 9; i++) {
        if (isDwarfPicked[i]) {
            numPickedDwarf++;
            pickedHeightSum += heights[i];
            lastPickedDwarfNo = i;
        }
    }

    if (pickedHeights.size() == 7 && pickedHeightSum == 100) {
        sort(pickedHeights.begin(), pickedHeights.end());

        for (int i = 0; i < 7; i++) {
            cout << pickedHeights[i] << endl;
        }

        exit(0);
    }

    for (int i = lastPickedDwarfNo + 1; i < 9; i++) {
        pickedHeights.push_back(heights[i]);

        isDwarfPicked[i] = true;

        performHeightDfs(heights, isDwarfPicked, pickedHeights);
        pickedHeights.pop_back();

        isDwarfPicked[i] = false;
    }
}

int main() {
    int heights[9];
    bool isDwarfPicked[9] = {false, false, false, false, false, false, false, false, false};
    vector<int> pickedHeights;

    for (int &height : heights) {
        cin >> height;
    }

    performHeightDfs(heights, isDwarfPicked, pickedHeights);

    return 0;
}
