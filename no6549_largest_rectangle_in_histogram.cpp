#include <iostream>
#include <vector>

using namespace std;

typedef struct Division {
    int leftEnd;
    int rightEnd;
} Division;

long long int findMaximumSurface(vector<long long int> &rectangleHeights, Division division) {
    if (division.leftEnd == division.rightEnd) return rectangleHeights[division.leftEnd];

    int center = (division.leftEnd + division.rightEnd) / 2;
    long long int maximumSurface = max(findMaximumSurface(rectangleHeights, {division.leftEnd, center}),
                                       findMaximumSurface(rectangleHeights, {center + 1, division.rightEnd}));
    Division stretched = {center, center + 1};
    long long int stretchedHeight = min(rectangleHeights[stretched.leftEnd], rectangleHeights[stretched.rightEnd]);

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

        if (numRectangle == 0) break;

        vector<long long int> rectangleHeights(numRectangle);

        for (long long int &boardHeight : rectangleHeights) {
            cin >> boardHeight;
        }

        cout << findMaximumSurface(rectangleHeights, {0, numRectangle - 1}) << endl;
    }

    return 0;
}
