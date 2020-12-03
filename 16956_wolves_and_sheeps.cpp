#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r;
    int c;

    cin >> r >> c;

    vector<string> farmMap(r);

    for (auto &farmRow : farmMap) {
        cin >> farmRow;

        for (char &farmElement : farmRow) {
            if (farmElement == '.') farmElement = 'D';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (farmMap[i][j] != 'W') continue;

            for (int k = 0; k < 4; k++) {
                int ni = i + "1201"[k] - '1';
                int nj = j + "0112"[k] - '1';

                if (ni >= 0 && ni < r && nj >= 0 && nj < c && farmMap[ni][nj] == 'S') {
                    cout << "0\n";

                    return 0;
                }
            }
        }
    }

    cout << "1\n";

    for (auto &farmRow : farmMap) {
        cout << farmRow << '\n';
    }

    return 0;
}
