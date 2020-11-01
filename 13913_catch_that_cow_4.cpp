#include <iostream>
#include <queue>

using namespace std;

int sourcePosition;
int timeCountAt[100001];
int previousPosition[100001];

void tracebackPositions(int currentPosition) {
    if (currentPosition != sourcePosition) {
        tracebackPositions(previousPosition[currentPosition]);
    }

    cout << currentPosition << ' ';
}

int main() {
    int destinationPosition;
    queue<int> bfsPositions;

    cin >> sourcePosition >> destinationPosition;

    timeCountAt[sourcePosition] = 1;

    bfsPositions.push(sourcePosition);

    while (!bfsPositions.empty()) {
        int currentPosition = bfsPositions.front();

        if (currentPosition == destinationPosition) {
            cout << timeCountAt[currentPosition] - 1 << '\n';

            tracebackPositions(destinationPosition);

            cout << '\n';

            return 0;
        }

        int adjacentPositions[] = {currentPosition + 1, currentPosition - 1, 2 * currentPosition};

        bfsPositions.pop();

        for (int adjacentPosition : adjacentPositions) {
            if (adjacentPosition >= 0 && adjacentPosition <= 100000 && !timeCountAt[adjacentPosition]) {
                timeCountAt[adjacentPosition] = timeCountAt[currentPosition] + 1;
                previousPosition[adjacentPosition] = currentPosition;

                bfsPositions.push(adjacentPosition);
            }
        }
    }
}
