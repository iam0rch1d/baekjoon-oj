#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // .first = <numerator>, .second = <denominator>
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> sum;
    int sumGcd;

    cin >> a.first >> a.second >> b.first >> b.second;

    sum.first = a.first * b.second + b.first * a.second;
    sum.second = a.second * b.second;
    sumGcd = __gcd(sum.first, sum.second);

    cout << sum.first / sumGcd << ' ' << sum.second / sumGcd << '\n';

    return 0;
}
