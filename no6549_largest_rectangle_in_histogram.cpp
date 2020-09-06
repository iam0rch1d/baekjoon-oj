#include <iostream>
#include <vector>

using namespace std;

typedef struct Division {
    int leftEnd;
    int rightEnd;
} Division;

long long dncMaximumSurface(vector<long long> &rectangleHeights, Division division) {
    if (division.leftEnd == division.rightEnd) return rectangleHeights[division.leftEnd];

    int center = (division.leftEnd + division.rightEnd) / 2;
    long long maximumSurface = max(dncMaximumSurface(rectangleHeights, {division.leftEnd, center}),
                                       dncMaximumSurface(rectangleHeights, {center + 1, division.rightEnd}));
    Division stretched = {center, center + 1};
    long long stretchedHeight = min(rectangleHeights[stretched.leftEnd], rectangleHeights[stretched.rightEnd]);

    maximumSurface = max(maximumSurface, 2 * stretchedHeight);

    while (stretched.leftEnd > division.leftEnd || stretched.rightEnd < division.rightEnd) {
        if (stretched.rightEnd < division.rightEnd
            && (stretched.leftEnd == division.leftEnd
                || rectangleHeights[stretched.leftEnd - 1] < rectangleHeights[stretched.rightEnd + 1])) {
            stretched.rightEnd++;
            stretchedHeight = min(stretchedHeight, rectangleHeights[stretched.rightEnd]);
        } else {
            stretched.leftEnd--;
            stretchedHeight = min(stretchedHeight, rectangleHeights[stretched.leftEnd]);
        }

        maximumSurface = max(maximumSurface, stretchedHeight * (stretched.rightEnd - stretched.leftEnd + 1));
    }

    return maximumSurface;
}

int main() {
    while (true) {
        int numRectangle;

        cin >> numRectangle;

        if (numRectangle == 0) return 0;

        vector<long long> rectangleHeights(numRectangle);

        for (long long &boardHeight : rectangleHeights) {
            cin >> boardHeight;
        }

        cout << dncMaximumSurface(rectangleHeights, {0, numRectangle - 1}) << endl;
    }
}
