#include <iostream>
#include <queue>

using namespace std;

bool isVisited[201][201];
bool canMakeC[201];

int main() {
    int capacities[3];
    int abcSum;
    queue<pair<int, int>> bfsAbs;

    cin >> capacities[0] >> capacities[1] >> capacities[2];

    isVisited[0][0] = true;
    canMakeC[capacities[2]] = true;
    abcSum = capacities[2];

    bfsAbs.emplace(0, 0);

    while (!bfsAbs.empty()) {
        int currentAbc[3] = {bfsAbs.front().first, bfsAbs.front().second, abcSum - currentAbc[0] - currentAbc[1]};

        bfsAbs.pop();

        for (int i = 0; i < 6; i++) {
            int adjacentAbc[] = {currentAbc[0], currentAbc[1], currentAbc[2]};
            int from = "001122"[i] - '0';
            int to = "120201"[i] - '0';

            if (adjacentAbc[from] + adjacentAbc[to] <= capacities[to]) {
                adjacentAbc[to] += adjacentAbc[from];
                adjacentAbc[from] = 0;
            } else {
                adjacentAbc[from] += adjacentAbc[to] - capacities[to];
                adjacentAbc[to] = capacities[to];
            }

            if (!isVisited[adjacentAbc[0]][adjacentAbc[1]]) {
                isVisited[adjacentAbc[0]][adjacentAbc[1]] = true;

                if (!adjacentAbc[0]) canMakeC[adjacentAbc[2]] = true;

                bfsAbs.emplace(adjacentAbc[0], adjacentAbc[1]);
            }
        }
    }

    for (int i = 0; i <= capacities[2]; i++) {
        if (canMakeC[i]) cout << i << ' ';
    }

    cout << '\n';

    return 0;
}
