#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Point {
    int x;
    int y;
} Point;

int square(int a) {
    return a * a;
}

int calculateDistanceSquare(Point &a, Point &b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int dncMinimumDistanceSquare(vector<Point>::iterator head, int size) {
    if (size == 2) return calculateDistanceSquare(*head, *(head + 1));

    if (size == 3)
        return min({calculateDistanceSquare(*head, *(head + 1)),
                    calculateDistanceSquare(*head, *(head + 2)),
                    calculateDistanceSquare(*(head + 1), *(head + 2))});

    int halfSize = size / 2;
    int minimumDistanceSquare = min(dncMinimumDistanceSquare(head, halfSize),
                                    dncMinimumDistanceSquare(head + halfSize, size - halfSize));
    int center = ((head + halfSize - 1)->x + (head + halfSize)->x) / 2;
    vector<Point> crossingCenters;

    for (int i = 0; i < size; i++) {
        if (square(center - (head + i)->x) < minimumDistanceSquare) {
            crossingCenters.push_back(*(head + i));
        }
    }

    int crossingCentersSize = crossingCenters.size();

    sort(crossingCenters.begin(), crossingCenters.end(), [](auto i, auto j) { return (i.y < j.y); });

    for (int i = 0; i < crossingCentersSize - 1; i++) {
        for (int j = i + 1;
             j < crossingCentersSize && square(crossingCenters[j].y - crossingCenters[i].y) < minimumDistanceSquare;
             j++) {
            minimumDistanceSquare = min(minimumDistanceSquare,
                                        calculateDistanceSquare(crossingCenters[i], crossingCenters[j]));
        }
    }

    return minimumDistanceSquare;
}

int main() {
    int numPoint;

    cin >> numPoint;

    vector<Point> points(numPoint);

    for (int i = 0; i < numPoint; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [](auto i, auto j) { return (i.x < j.x); });

    cout << dncMinimumDistanceSquare(points.begin(), numPoint) << endl;

    return 0;
}
