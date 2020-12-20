#include <iostream>
#include <vector>

using namespace std;

#define MAX_FACTOR 44721

bool eratosthenesSieve[MAX_FACTOR + 1];
vector<long long> primeSquares;

long long calculateSquareYesYes(int primeSquareNo, long long product, long long x) {
    if (primeSquareNo >= primeSquares.size()) return 0;

    long long intersectedProduct = product * primeSquares[primeSquareNo];

    if (intersectedProduct > x) return 0;

    long long ret = x / intersectedProduct;

    ret += calculateSquareYesYes(primeSquareNo + 1, product, x);
    ret -= calculateSquareYesYes(primeSquareNo + 1, intersectedProduct, x);

    return ret;
}

int main() {
    long long k;
    long long ansLeft = 1;
    long long ansRight = 2000000000;
    long long ans;

    for (int i = 2; i <= MAX_FACTOR; i++) {
        if (eratosthenesSieve[i]) continue;

        primeSquares.push_back(i * i);

        for (int j = i + i; j <= MAX_FACTOR; j += i) {
            eratosthenesSieve[j] = true;
        }
    }

    cin >> k;

    while (ansLeft <= ansRight) {
        long long ansMid = (ansLeft + ansRight) / 2;
        long long squareNoNo = ansMid - calculateSquareYesYes(0, 1, ansMid);

        if (squareNoNo >= k) {
            ans = ansMid;
            ansRight = ansMid - 1;
        } else ansLeft = ansMid + 1;
    }

    cout << ans << '\n';

    return 0;
}
