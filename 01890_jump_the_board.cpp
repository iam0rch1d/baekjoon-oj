#include <iostream>
#include <vector>

#define MAX_SIZE 100

using namespace std;

long long pathCountCache[MAX_SIZE][MAX_SIZE];

int main() {
    int n;

    cin >> n;

    vector<vector<long long>> jumpDistances(n, vector<long long>(n));

    for (auto &jumpDistanceRow : jumpDistances) {
        for (auto &jumpDistance : jumpDistanceRow) {
            cin >> jumpDistance;
        }
    }

    pathCountCache[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!pathCountCache[i][j] || (i == n - 1 && j == n - 1)) continue;

            for (int k = 0; k < 2; k++) {
                long long ni = i + ("10"[k] - '0') * jumpDistances[i][j];
                long long nj = j + ("01"[k] - '0') * jumpDistances[i][j];

                if (ni >= n || nj >= n) continue;

                pathCountCache[ni][nj] += pathCountCache[i][j];
            }
        }
    }

    cout << pathCountCache[n - 1][n - 1] << '\n';

    return 0;
}
