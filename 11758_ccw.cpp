#include <iostream>

using namespace std;

int main() {
    pair<int, int> points[3];
    pair<int, int> vectors[2];

    for (auto &point : points) {
        cin >> point.first >> point.second;
    }

    vectors[0] = {points[1].first - points[0].first, points[1].second - points[0].second};
    vectors[1] = {points[1].first - points[2].first, points[1].second - points[2].second};

    int vectorProductZ = vectors[0].first * vectors[1].second - vectors[0].second * vectors[1].first;

    if (vectorProductZ > 0) cout << -1;
    else if (vectorProductZ < 0) cout << 1;
    else cout << 0;

    cout << '\n';

    return 0;
}
