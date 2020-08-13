#include <algorithm>
#include <iostream>
#include <vector>

#define NUM_DWARF 7
#define NUM_PERSON 9

using namespace std;

void performHeightDfs(const int heights[NUM_PERSON], bool isDwarfPicked[NUM_PERSON], vector<int> pickedHeights) {
    int numPickedDwarf = 0;
    int pickedHeightSum = 0;
    int lastPickedDwarfNo = -1;

    for (int i = 0; i < NUM_PERSON; i++) {
        if (isDwarfPicked[i]) {
            numPickedDwarf++;
            pickedHeightSum += heights[i];
            lastPickedDwarfNo = i;
        }
    }

    if (pickedHeights.size() == NUM_DWARF && pickedHeightSum == 100) {
        sort(pickedHeights.begin(), pickedHeights.end());

        for (int i = 0; i < NUM_DWARF; i++) {
            cout << pickedHeights[i] << endl;
        }

        exit(0);
    }

    for (int i = lastPickedDwarfNo + 1; i < NUM_PERSON; i++) {
        pickedHeights.push_back(heights[i]);

        isDwarfPicked[i] = true;

        performHeightDfs(heights, isDwarfPicked, pickedHeights);
        pickedHeights.pop_back();

        isDwarfPicked[i] = false;
    }
}

int main() {
    int heights[NUM_PERSON];
    bool isDwarfPicked[NUM_PERSON] = {false, false, false, false, false, false, false, false, false};
    vector<int> pickedHeights;

    for (int &height : heights) {
        cin >> height;
    }

    performHeightDfs(heights, isDwarfPicked, pickedHeights);

    return 0;
}
