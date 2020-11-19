#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;
int map[100][100];

bool bfsCanMove(int minElement, int maxElement) {
    if (map[0][0] < minElement || map[0][0] > maxElement) return false;

    vector<vector<bool>> isVisited(n, vector<bool>(n));
    queue<pair<int, int>> bfsPoints;

    isVisited[0][0] = true;
    bfsPoints.push({0, 0});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        if (y == n - 1 && x == n - 1) return true;

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n
                || isVisited[ny][nx] || map[ny][nx] < minElement || map[ny][nx] > maxElement) {
                continue;
            }

            isVisited[ny][nx] = true;

            bfsPoints.push({ny, nx});
        }
    }

    return false;
}

bool canMove(int withDifference) {
    for (int i = 0; i + withDifference <= 200; i++) {
        if (bfsCanMove(i, i + withDifference)) return true;
    }

    return false;
}

int main() {
    int differenceLeft = 0;
    int differenceRight;
    int difference;
    int maxElement = 0;
    int minElement = 201;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            maxElement = max(maxElement, map[i][j]);
            minElement = min(minElement, map[i][j]);
        }
    }

    differenceRight = maxElement - minElement;

    while (differenceLeft <= differenceRight) {
        int differenceMid = (differenceLeft + differenceRight) / 2;

        if (canMove(differenceMid)) {
            difference = differenceMid;
            differenceRight = differenceMid - 1;
        } else differenceLeft = differenceMid + 1;
    }

    cout << difference << '\n';

    return 0;
}
