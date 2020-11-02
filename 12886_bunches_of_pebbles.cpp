#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isVisited[501][501][501];

int main() {
    vector<int> abc(3);

    cin >> abc[0] >> abc[1] >> abc[2];

    if ((abc[0] + abc[1] + abc[2]) % 3) {
        cout << "0\n";

        return 0;
    }

    queue<vector<int>> bfsAbcs;

    sort(abc.begin(), abc.end());

    isVisited[abc[0]][abc[1]][abc[2]] = true;

    bfsAbcs.push(abc);

    while (!bfsAbcs.empty()) {
        auto currentAbc = bfsAbcs.front();

        if (currentAbc[0] == currentAbc[1] && currentAbc[1] == currentAbc[2]) {
            cout << "1\n";

            return 0;
        }

        bfsAbcs.pop();

        vector<int> adjacentAbcs[] = {{currentAbc[0] + currentAbc[0],
                                      currentAbc[1] - currentAbc[0],
                                      currentAbc[2]},
                                      {currentAbc[0] + currentAbc[0],
                                      currentAbc[1],
                                      currentAbc[2] - currentAbc[0]},
                                      {currentAbc[0],
                                      currentAbc[1] + currentAbc[1],
                                      currentAbc[2] - currentAbc[1]}};

        for (auto &adjacentAbc : adjacentAbcs) {
            sort(adjacentAbc.begin(), adjacentAbc.end());

            if (!isVisited[adjacentAbc[0]][adjacentAbc[1]][adjacentAbc[2]]) {
                isVisited[adjacentAbc[0]][adjacentAbc[1]][adjacentAbc[2]] = true;

                bfsAbcs.push(adjacentAbc);
            }
        }
    }

    cout << "0\n";

    return 0;
}
