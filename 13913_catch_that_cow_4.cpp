#include <iostream>
#include <queue>

using namespace std;

int sourcePosition;
int timeAt[100001];
int previousPositions[100001];

void tracebackPositions(int currentPosition) {
    if (currentPosition != sourcePosition) {
        tracebackPositions(previousPositions[currentPosition]);
    }

    cout << currentPosition << ' ';
}

int main() {
    int destinationPosition;
    queue<int> bfsPositions;

    cin >> sourcePosition >> destinationPosition;

    timeAt[sourcePosition] = 1;

    bfsPositions.push(sourcePosition);

    while (!bfsPositions.empty()) {
        int currentPosition = bfsPositions.front();

        if (currentPosition == destinationPosition) {
            cout << timeAt[currentPosition] - 1 << '\n';

            tracebackPositions(destinationPosition);

            cout << '\n';

            return 0;
        }

        int adjacentPositions[] = {currentPosition + 1, currentPosition - 1, 2 * currentPosition};

        bfsPositions.pop();

        for (int adjacentPosition : adjacentPositions) {
            if (adjacentPosition >= 0 && adjacentPosition <= 100000 && !timeAt[adjacentPosition]) {
                timeAt[adjacentPosition] = timeAt[currentPosition] + 1;
                previousPositions[adjacentPosition] = currentPosition;

                bfsPositions.push(adjacentPosition);
            }
        }
    }
}
