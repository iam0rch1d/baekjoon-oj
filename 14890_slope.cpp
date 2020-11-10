#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int l;
    bool canPass = true;
    int pathCount = 0;

    cin >> n >> l;

    vector<vector<int>> map(n, vector<int>(n));

    for (auto &mapRow : map) {
        for (int &mapElement : mapRow) {
            cin >> mapElement;
        }
    }

    for (int i = 0; i < n; i++) {
        vector<bool> isSlope(n, false);

        for (int x = 0; x < n - 1; x++) {
            if (map[i][x + 1] == map[i][x]) continue;
            else if (map[i][x + 1] == map[i][x] + 1) {
                for (int j = 0; j < l; j++) {
                    int nx = x - j;

                    if (nx < 0 || map[i][nx] != map[i][x] || isSlope[nx]) {
                        canPass = false;

                        break;
                    }

                    isSlope[nx] = true;
                }
            } else if (map[i][x + 1] == map[i][x] - 1) {
                for (int j = 1; j <= l; j++) {
                    int nx = x + j;

                    if (nx >= n || map[i][nx] != map[i][x] - 1 || isSlope[nx]) {
                        canPass = false;

                        break;
                    }

                    isSlope[nx] = true;
                }
            } else canPass = false;

            if (!canPass) break;
        }

        pathCount += canPass;
        canPass = true;
    }

    for (int i = 0; i < n; i++) {
        vector<bool> isSlope(n, false);

        for (int y = 0; y < n - 1; y++) {
            if (map[y + 1][i] == map[y][i]) continue;
            else if (map[y + 1][i] == map[y][i] + 1) {
                for (int j = 0; j < l; j++) {
                    int ny = y - j;

                    if (ny < 0 || map[ny][i] != map[y][i] || isSlope[ny]) {
                        canPass = false;

                        break;
                    }

                    isSlope[ny] = true;
                }
            } else if (map[y + 1][i] == map[y][i] - 1) {
                for (int j = 1; j <= l; j++) {
                    int ny = y + j;

                    if (ny >= n || map[ny][i] != map[y][i] - 1 || isSlope[ny]) {
                        canPass = false;

                        break;
                    }

                    isSlope[ny] = true;
                }
            } else canPass = false;

            if (!canPass) break;
        }

        pathCount += canPass;
        canPass = true;
    }

    cout << pathCount << '\n';

    return 0;
}
