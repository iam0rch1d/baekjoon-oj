#include <iostream>
#include <queue>

using namespace std;

int buttonPushesAt[1000001];

int main() {
    int f;
    int s;
    int g;
    int u;
    int d;
    queue<int> bfsFloors;

    cin >> f >> s >> g >> u >> d;

    buttonPushesAt[s] = 1;

    bfsFloors.push(s);

    while (!bfsFloors.empty()) {
        int currentFloor = bfsFloors.front();

        if (currentFloor == g) {
            cout << buttonPushesAt[g] - 1 << '\n';

            return 0;
        }

        int adjacentFloors[] = {currentFloor + u, currentFloor - d};

        bfsFloors.pop();

        for (int adjacentFloor : adjacentFloors) {
            if (adjacentFloor < 1 || adjacentFloor > f || buttonPushesAt[adjacentFloor]) continue;

            buttonPushesAt[adjacentFloor] = buttonPushesAt[currentFloor] + 1;

            bfsFloors.push(adjacentFloor);
        }
    }

    cout << "use the stairs\n";

    return 0;
}
