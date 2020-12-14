#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 15

int main() {
    int n;
    int m;
    int maxValue = 0;

    cin >> n >> m;

    vector<string> map(n);

    for (auto &mapRow : map) {
        cin >> mapRow;
    }

    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int k1 = 0;; k1++) {
                if (i1 - k1 < 0 || i1 + k1 >= n || j1 - k1 < 0 || j1 + k1 >= m
                    || map[i1 - k1][j1] != '#' || map[i1 + k1][j1] != '#'
                    || map[i1][j1 - k1] != '#' || map[i1][j1 + k1] != '#') {
                    break;
                }

                map[i1 - k1][j1] = '@';
                map[i1 + k1][j1] = '@';
                map[i1][j1 - k1] = '@';
                map[i1][j1 + k1] = '@';

                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < m; j2++) {
                        for (int k2 = 0;; k2++) {
                            if (i2 - k2 < 0 || i2 + k2 >= n || j2 - k2 < 0 || j2 + k2 >= m
                                || map[i2 - k2][j2] != '#' || map[i2 + k2][j2] != '#'
                                || map[i2][j2 - k2] != '#' || map[i2][j2 + k2] != '#') {
                                break;
                            }

                            maxValue = max(maxValue, (4 * k1 + 1) * (4 * k2 + 1));
                        }
                    }
                }
            }

            for (int k1 = 0;; k1++) {
                if (i1 - k1 < 0 || i1 + k1 >= n || j1 - k1 < 0 || j1 + k1 >= m
                    || map[i1 - k1][j1] != '@' || map[i1 + k1][j1] != '@'
                    || map[i1][j1 - k1] != '@' || map[i1][j1 + k1] != '@') {
                    break;
                }

                map[i1 - k1][j1] = '#';
                map[i1 + k1][j1] = '#';
                map[i1][j1 - k1] = '#';
                map[i1][j1 + k1] = '#';
            }
        }
    }

    cout << maxValue << '\n';

    return 0;
}
