#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Building {
    int x1;
    int y1;
    int x2;
};

struct Point {
    int x;
    int y;
};

typedef vector<Point> Skyline;

void append(Skyline &skyline, Point point) {
    if (!skyline.empty()) {
        if (skyline.back().y == point.y) return;

        if (skyline.back().x == point.x) {
            skyline.back().y = point.y;

            return;
        }
    }

    skyline.push_back(point);
}

Skyline mergeSkyline(Skyline left, Skyline right) {
    int leftIndex = 0;
    int leftSize = left.size();
    int rightIndex = 0;
    int rightSize = right.size();
    Skyline mergedSkyline;
    int leftHeadY = 0;
    int rightHeadY = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        auto &leftHead = left[leftIndex];
        auto &rightHead = right[rightIndex];

        if (leftHead.x < rightHead.x) {
            leftHeadY = leftHead.y;

            append(mergedSkyline, {leftHead.x, max(leftHeadY, rightHeadY)});

            leftIndex++;
        } else {
            rightHeadY = rightHead.y;

            append(mergedSkyline, {rightHead.x, max(leftHeadY, rightHeadY)});

            rightIndex++;
        }
    }

    while (leftIndex < leftSize) {
        append(mergedSkyline, left[leftIndex++]);
    }

    while (rightIndex < rightSize) {
        append(mergedSkyline, right[rightIndex++]);
    }

    return mergedSkyline;
}

Skyline dncSkyline(vector<Building> &buildings, int left, int right) {
    if (left == right) {
        return {{buildings[left].x1, buildings[left].y1},
                {buildings[left].x2, 0}};
    }

    int mid = (left + right) / 2;

    return mergeSkyline(dncSkyline(buildings, left, mid), dncSkyline(buildings, mid + 1, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    vector<Building> buildings(n);

    for (auto &building : buildings) {
        cin >> building.x1 >> building.y1 >> building.x2;
    }

    sort(buildings.begin(), buildings.end(), [](auto &i, auto &j) {
        return tie(i.x1, i.y1, i.x2) < tie(j.x1, j.y1, j.x2);
    });

    auto skyline = dncSkyline(buildings, 0, n - 1);

    for (auto &point : skyline) {
        cout << point.x << ' ' << point.y << ' ';
    }

    cout << '\n';

    return 0;
}
