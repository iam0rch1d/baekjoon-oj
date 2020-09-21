#include <iostream>
#include <tuple>

using namespace std;

int square(int x) {
    return x * x;
}

bool isIncluded(pair<int, int> point, tuple<int, int, int> circle) {
    return square(point.first - get<0>(circle)) + square(point.second - get<1>(circle)) < square(get<2>(circle));
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        pair<int, int> source;
        pair<int, int> destination;
        int numCircle;
        int passingCircleCount = 0;

        cin >> source.first >> source.second >> destination.first >> destination.second >> numCircle;

        while (numCircle--) {
            tuple<int, int, int> circle;

            cin >> get<0>(circle) >> get<1>(circle) >> get<2>(circle);

            if (isIncluded(source, circle) ^ isIncluded(destination, circle)) passingCircleCount++;
        }

        cout << passingCircleCount << endl;
    }

    return 0;
}
