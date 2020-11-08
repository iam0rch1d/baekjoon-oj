#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int k;

    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (auto &ai : a) {
        for (auto &aij : ai) {
            cin >> aij;
        }
    }

    cin >> k;

    while (k--) {
        int y1;
        int x1;
        int y2;
        int x2;
        int sum = 0;

        cin >> y1 >> x1 >> y2 >> x2;

        --y1;
        --x1;

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                sum += a[i][j];
            }
        }

        cout << sum << '\n';
    }

    return 0;
}
