#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int square(int x) {
    return x * x;
}

int squareDistance(Point p1, Point p2) {
    return square(p2.x - p1.x) + square(p2.y - p1.y);
}

int dncMinDistance(vector<Point> &points, int left, int right) {
    int divisionSize = right - left + 1;
    int mid = (left + right) / 2;

    if (divisionSize == 2) return squareDistance(points[left], points[right]);
    else if (divisionSize == 3) {
        return min({squareDistance(points[left], points[mid]),
                    squareDistance(points[left], points[right]),
                    squareDistance(points[mid], points[right])});
    }

    int ret = min(dncMinDistance(points, left, mid), dncMinDistance(points, mid + 1, right));
    vector<Point> centerPoints;
    int centerPointsSize;

    for (int i = left; i <= right; i++) {
        if (square(points[mid].x - points[i].x) < ret) centerPoints.push_back(points[i]);
    }

    sort(centerPoints.begin(), centerPoints.end(), [](auto &i, auto &j) { return tie(i.y, i.x) < tie(j.y, j.x); });

    centerPointsSize = centerPoints.size();

    for (int i = 0; i < centerPointsSize - 1; i++) {
        for (int j = i + 1; j < centerPointsSize; j++) {
            if (square(centerPoints[i].y - centerPoints[j].y) < ret) {
                ret = min(ret, squareDistance(centerPoints[i], centerPoints[j]));
            } else break;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<Point> points(n);

    for (auto &point : points) {
        cin >> point.x >> point.y;
    }

    sort(points.begin(), points.end(), [](auto &i, auto &j) { return tie(i.x, i.y) < tie(j.x, j.y); });

    cout << dncMinDistance(points, 0, n - 1) << '\n';

    return 0;
}
