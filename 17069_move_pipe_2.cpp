#include <iostream>

#define MAX_SIZE 32

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
long long methodCountCache[MAX_SIZE][MAX_SIZE][3];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        if (map[0][i]) break;

        methodCountCache[0][i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (!map[i][j]) {
                methodCountCache[i][j][0] = methodCountCache[i][j - 1][0] + methodCountCache[i][j - 1][1];
                methodCountCache[i][j][2] = methodCountCache[i - 1][j][1] + methodCountCache[i - 1][j][2];

                if (!map[i - 1][j] && !map[i][j - 1]) {
                    methodCountCache[i][j][1] = methodCountCache[i - 1][j - 1][0]
                                                + methodCountCache[i - 1][j - 1][1]
                                                + methodCountCache[i - 1][j - 1][2];
                }
            }
        }
    }

    cout << methodCountCache[n - 1][n - 1][0]
            + methodCountCache[n - 1][n - 1][1]
            + methodCountCache[n - 1][n - 1][2] << '\n';

    return 0;
}
