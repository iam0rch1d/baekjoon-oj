#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Building {
    int left;
    int height;
    int right;
};

typedef vector<pair<int, int>> Vpii;  // .first = <position>, .second = <height>

void append(Vpii &vpii, pair<int, int> pii) {
    if (!vpii.empty()) {
        if (vpii.back().second == pii.second) return;

        if (vpii.back().first == pii.first) {
            vpii.back().second = pii.second;

            return;
        }
    }

    vpii.push_back(pii);
}

Vpii mergeSkyline(Vpii left, Vpii right) {
    int leftIndex = 0;
    int leftSize = left.size();
    int rightIndex = 0;
    int rightSize = right.size();
    Vpii mergedSkyline;
    int leftHeadHeight = 0;
    int rightHeadHeight = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        auto &leftHead = left[leftIndex];
        auto &rightHead = right[rightIndex];

        if (leftHead.first < rightHead.first) {
            leftHeadHeight = leftHead.second;

            append(mergedSkyline, {leftHead.first, max(leftHeadHeight, rightHeadHeight)});

            leftIndex++;
        } else {
            rightHeadHeight = rightHead.second;

            append(mergedSkyline, {rightHead.first, max(leftHeadHeight, rightHeadHeight)});

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

Vpii dncSkyline(vector<Building> &buildings, int left, int right) {
    if (left == right) {
        return {{buildings[left].left, buildings[left].height},
                {buildings[left].right, 0}};
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
        cin >> building.left >> building.height >> building.right;
    }

    sort(buildings.begin(), buildings.end(), [](auto &i, auto &j) {
        return tie(i.left, i.height, i.right) < tie(j.left, j.height, j.right);
    });

    auto skyline = dncSkyline(buildings, 0, n - 1);

    for (auto &pii : skyline) {
        cout << pii.first << ' ' << pii.second << ' ';
    }

    cout << '\n';

    return 0;
}
