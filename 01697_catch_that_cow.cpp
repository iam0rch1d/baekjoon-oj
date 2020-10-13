#include <iostream>
#include <queue>

using namespace std;

int timeCount[100001];

int main() {
    int sourcePosition;
    int destinationPosition;
    queue<int> bfsPositions;

    cin >> sourcePosition >> destinationPosition;

    timeCount[sourcePosition] = 1;

    bfsPositions.push(sourcePosition);

    while (!bfsPositions.empty()) {
        int currentPosition = bfsPositions.front();
        int adjacentPositions[3] = {currentPosition + 1, currentPosition - 1, 2 * currentPosition};

        if (currentPosition == destinationPosition) {
            cout << timeCount[currentPosition] - 1 << '\n';

            return 0;
        }

        bfsPositions.pop();

        for (int adjacentPosition : adjacentPositions) {
            if (adjacentPosition >= 0 && adjacentPosition <= 100000 && !timeCount[adjacentPosition]) {
                timeCount[adjacentPosition] = timeCount[currentPosition] + 1;

                bfsPositions.push(adjacentPosition);
            }
        }
    }
}
