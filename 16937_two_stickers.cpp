#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    int h;
    int w;
    int n;
    int maxSurface = 0;

    cin >> h >> w >> n;

    vector<pair<int, int>> stickers(n);

    for (auto &sticker : stickers) {
        cin >> sticker.first >> sticker.second;
    }

    for (int i = 0; i < n - 1; i++) {
        int r1;
        int c1;

        tie(r1, c1) = stickers[i];

        for (int j = i + 1; j < n; j++) {
            int r2;
            int c2;

            tie(r2, c2) = stickers[j];

            for (int rotation1 = 0; rotation1 < 2; rotation1++) {
                for (int rotation2 = 0; rotation2 < 2; rotation2++) {
                    if ((r1 + r2 <= h && max(c1, c2) <= w) || (r1 + r2 <= w && max(c1, c2) <= h)) {
                        maxSurface = max(maxSurface, r1 * c1 + r2 * c2);
                    }

                    swap(r2, c2);
                }

                swap(r1, c1);
            }
        }
    }

    cout << maxSurface << '\n';

    return 0;
}
