#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int leftEnd;
    int rightEnd;
} Division;

long long dncMaxSurface(vector<long long> &rectangleHeights, Division division) {
    if (division.leftEnd == division.rightEnd) return rectangleHeights[division.leftEnd];

    int center = (division.leftEnd + division.rightEnd) / 2;
    long long maxSurface = max(dncMaxSurface(rectangleHeights, {division.leftEnd, center}),
                               dncMaxSurface(rectangleHeights, {center + 1, division.rightEnd}));
    Division stretched = {center, center + 1};
    long long stretchedHeight = min(rectangleHeights[stretched.leftEnd], rectangleHeights[stretched.rightEnd]);

    maxSurface = max(maxSurface, 2 * stretchedHeight);

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

        maxSurface = max(maxSurface, stretchedHeight * (stretched.rightEnd - stretched.leftEnd + 1));
    }

    return maxSurface;
}

int main() {
    int numRectangle;

    cin >> numRectangle;

    vector<long long> rectangleHeights(numRectangle);

    for (long long &boardHeight : rectangleHeights) {
        cin >> boardHeight;
    }

    cout << dncMaxSurface(rectangleHeights, {0, numRectangle - 1}) << '\n';
}
