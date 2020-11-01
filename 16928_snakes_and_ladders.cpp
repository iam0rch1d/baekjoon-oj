#include <iostream>
#include <queue>

using namespace std;

int rollCountAt[100];
int teleporters[100];

int main() {
    int n;
    int m;
    queue<int> bfsPositions;

    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        int x;
        int y;

        cin >> x >> y;

        teleporters[x - 1] = y - x;
    }

    rollCountAt[0] = 1;

    bfsPositions.push(0);

    while (!bfsPositions.empty()) {
        int currentPosition = bfsPositions.front();

        if (currentPosition == 99) {
            cout << rollCountAt[99] - 1 << '\n';

            return 0;
        }

        bfsPositions.pop();

        for (int i = 1; i <= 6; i++) {
            int adjacentPosition = currentPosition + i;

            adjacentPosition += teleporters[adjacentPosition];

            if (adjacentPosition < 0 || adjacentPosition >= 100 || rollCountAt[adjacentPosition]) continue;

            rollCountAt[adjacentPosition] = rollCountAt[currentPosition] + 1;

            bfsPositions.push(adjacentPosition);
        }
    }
}
