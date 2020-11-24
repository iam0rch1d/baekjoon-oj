#include <iostream>
#include <vector>

#define MAX_SIZE 100

using namespace std;

int crossSizes[MAX_SIZE][MAX_SIZE];
int isCovered[MAX_SIZE][MAX_SIZE];

int main() {
    int n;
    int m;
    int maxCrossSize;
    int crossCount = 0;

    cin >> n >> m;

    vector<vector<bool>> map(n, vector<bool>(m));

    maxCrossSize = min(n, m) + 1 / 2;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] == '*';
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (!map[i][j]) continue;

            for (int k = 1; k <= maxCrossSize; k++) {
                bool hasCross = true;

                for (int l = 0; l < 4; l++) {
                    int ni = i + k * ("1201"[l] - '1');
                    int nj = j + k * ("0112"[l] - '1');

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || !map[ni][nj]) {
                        hasCross = false;

                        break;
                    }
                }

                if (hasCross) {
                    crossSizes[i][j] = k;
                    isCovered[i][j] = true;

                    for (int l = 0; l < 4; l++) {
                        int ni = i + k * ("1201"[l] - '1');
                        int nj = j + k * ("0112"[l] - '1');

                        isCovered[ni][nj] = true;
                    }
                } else break;
            }

            if (crossSizes[i][j]) crossCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] && !isCovered[i][j]) {
                cout << "-1\n";

                return 0;
            }
        }
    }

    cout << crossCount << '\n';

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (crossSizes[i][j]) cout << i + 1 << ' ' << j + 1 << ' ' << crossSizes[i][j] << '\n';
        }
    }

    return 0;
}
