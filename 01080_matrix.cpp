#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int inversionCount = 0;

    cin >> n >> m;

    vector<vector<unsigned>> shouldInverse(n, vector<unsigned>(m));

    for (int i = 0; i < n; i++) {
        string aRow;

        cin >> aRow;

        for (int j = 0; j < m; j++) {
            shouldInverse[i][j] = aRow[j] == '1';
        }
    }

    for (int i = 0; i < n; i++) {
        string bRow;

        cin >> bRow;

        for (int j = 0; j < m; j++) {
            shouldInverse[i][j] ^= bRow[j] == '1';
        }
    }

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (shouldInverse[i][j]) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        shouldInverse[i + k][j + l] ^= true;
                    }
                }

                inversionCount++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (shouldInverse[i][j]) {
                cout << "-1\n";

                return 0;
            }
        }
    }

    cout << inversionCount << '\n';

    return 0;
}
