#include <iostream>
#include <vector>

using namespace std;

int v[100];
bool canPlayCache[101][1001];

int main() {
    int n;
    int s;
    int m;

    cin >> n >> s >> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    canPlayCache[0][s] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (canPlayCache[i][j]) {
                if (j - v[i] >= 0) canPlayCache[i + 1][j - v[i]] = true;

                if (j + v[i] <= m) canPlayCache[i + 1][j + v[i]] = true;
            }
        }
    }

    for (int i = m; i >= 0; i--) {
        if (canPlayCache[n][i]) {
            cout << i << '\n';

            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
