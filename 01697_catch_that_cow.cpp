#include <iostream>
#include <queue>

using namespace std;

int timeCountAt[100001];

int main() {
    int sourcePosition;
    int destinationPosition;
    queue<int> bfsPositions;

    cin >> sourcePosition >> destinationPosition;

    timeCountAt[sourcePosition] = 1;

    bfsPositions.push(sourcePosition);

    while (!bfsPositions.empty()) {
        int currentPosition = bfsPositions.front();

        if (currentPosition == destinationPosition) {
            cout << timeCountAt[currentPosition] - 1 << '\n';

            return 0;
        }

        int adjacentPositions[] = {currentPosition + 1, currentPosition - 1, 2 * currentPosition};

        bfsPositions.pop();

        for (int adjacentPosition : adjacentPositions) {
            if (adjacentPosition >= 0 && adjacentPosition <= 100000 && !timeCountAt[adjacentPosition]) {
                timeCountAt[adjacentPosition] = timeCountAt[currentPosition] + 1;

                bfsPositions.push(adjacentPosition);
            }
        }
    }
}
