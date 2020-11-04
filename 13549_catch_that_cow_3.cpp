#include <iostream>
#include <queue>

using namespace std;

int timeAt[100001];

int main() {
    int sourcePosition;
    int destinationPosition;
    queue<int> bfsPositions;

    cin >> sourcePosition >> destinationPosition;

    timeAt[sourcePosition] = 1;

    bfsPositions.push(sourcePosition);

    while (!bfsPositions.empty()) {
        int currentPosition = bfsPositions.front();

        if (currentPosition == destinationPosition) {
            cout << timeAt[currentPosition] - 1 << '\n';

            return 0;
        }

        int teleportPosition = currentPosition * 2;
        int adjacentPositions[] = {currentPosition + 1, currentPosition - 1};

        bfsPositions.pop();

        while (teleportPosition <= 100000 && !timeAt[teleportPosition]) {
            timeAt[teleportPosition] = timeAt[currentPosition];

            bfsPositions.push(teleportPosition);

            teleportPosition *= 2;
        }

        for (int adjacentPosition : adjacentPositions) {
            if (adjacentPosition >= 0 && adjacentPosition <= 100000 && !timeAt[adjacentPosition]) {
                timeAt[adjacentPosition] = timeAt[currentPosition] + 1;

                bfsPositions.push(adjacentPosition);
            }
        }
    }

    return 0;
}
