#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int m;
    int n;
    int sqrtM;
    int sqrtN;
    int squareSum = 0;

    cin >> m >> n;

    sqrtM = ceil(sqrt(m));
    sqrtN = (int) sqrt(n);

    if (sqrtM * sqrtM > n) {
        cout << "-1\n";

        return 0;
    }

    for (int i = sqrtM; i <= sqrtN; i++) {
        squareSum += i * i;
    }

    cout << squareSum << '\n' << sqrtM * sqrtM << '\n';

    return 0;
}
