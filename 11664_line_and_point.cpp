#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    double x{};
    double y{};
    double z{};
};

Point operator+(Point a, Point b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Point operator*(double m, Point a) {
    return {m * a.x, m * a.y, m * a.z};
}

double abs(Point a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int main() {
    cout.precision(10);

    double ax;
    double ay;
    double az;
    double bx;
    double by;
    double bz;
    double cx;
    double cy;
    double cz;
    double mLeft = 0;
    double mRight = 1;

    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

    Point a{ax, ay, az};
    Point b{bx, by, bz};
    Point c{cx, cy, cz};

    while (abs(mRight - mLeft) > 1e-9) {
        double m1 = mLeft + (mRight - mLeft) / 3;
        double m2 = mRight - (mRight - mLeft) / 3;
        Point p1 = a + m1 * (b - a);
        Point p2 = a + m2 * (b - a);

        if (abs(p1 - c) > abs(p2 - c)) mLeft = m1;
        else mRight = m2;
    }

    cout << fixed << abs((a + (mLeft + mRight) / 2 * (b - a)) - c) << '\n';

    return 0;
}
