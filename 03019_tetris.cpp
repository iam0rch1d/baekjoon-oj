#include <iostream>

using namespace std;

int c;
int placedHeights[100];

bool canBuild(int onColumn, string toPlaceBottoms) {
    int toPlaceBottomsSize = toPlaceBottoms.size();

    if (onColumn + toPlaceBottomsSize > c) return false;

    for (int i = 0; i < toPlaceBottomsSize; i++) {
        if (placedHeights[onColumn] + toPlaceBottoms[i] - toPlaceBottoms[0] != placedHeights[onColumn + i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int p;
    int buildCount = 0;

    cin >> c >> p;

    for (int i = 0; i < c; i++) {
        cin >> placedHeights[i];
    }

    for (int i = 0; i < c; i++) {
        if (p == 1) buildCount += canBuild(i, "0") + canBuild(i, "0000");
        else if (p == 2) buildCount += canBuild(i, "00");
        else if (p == 3) buildCount += canBuild(i, "001") + canBuild(i, "10");
        else if (p == 4) buildCount += canBuild(i, "100") + canBuild(i, "01");
        else if (p == 5) buildCount += canBuild(i, "000") + canBuild(i, "10") + canBuild(i, "101") + canBuild(i, "01");
        else if (p == 6) buildCount += canBuild(i, "000") + canBuild(i, "11") + canBuild(i, "011") + canBuild(i, "20");
        else if (p == 7) buildCount += canBuild(i, "000") + canBuild(i, "11") + canBuild(i, "110") + canBuild(i, "02");
    }

    cout << buildCount << '\n';

    return 0;
}
