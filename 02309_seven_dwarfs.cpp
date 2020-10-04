#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int heights[9];
bool isDwarfPicked[9];

void backtrackHeight(vector<int> &pickedHeights) {
    int pickedDwarfCount = 0;
    int pickedHeightSum = 0;
    int lastPickedDwarfNo = -1;

    for (int i = 0; i < 9; i++) {
        if (isDwarfPicked[i]) {
            pickedDwarfCount++;
            pickedHeightSum += heights[i];
            lastPickedDwarfNo = i;
        }
    }

    if (pickedHeights.size() == 7 && pickedHeightSum == 100) {
        sort(pickedHeights.begin(), pickedHeights.end());

        for (int i = 0; i < 7; i++) {
            cout << pickedHeights[i] << '\n';
        }

        exit(0);
    }

    for (int i = lastPickedDwarfNo + 1; i < 9; i++) {
        pickedHeights.push_back(heights[i]);

        isDwarfPicked[i] = true;

        backtrackHeight(pickedHeights);
        pickedHeights.pop_back();

        isDwarfPicked[i] = false;
    }
}

int main() {
    vector<int> pickedHeights;

    for (int &height : heights) {
        cin >> height;
    }

    backtrackHeight(pickedHeights);

    return 0;
}
