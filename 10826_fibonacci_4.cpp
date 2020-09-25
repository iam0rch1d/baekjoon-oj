#include <iostream>
#include <vector>

using namespace std;

vector<int> operator+(const vector<int> &a, const vector<int> &b) {
    if (a.size() < b.size()) return operator+(b, a);

    int aSize = a.size();
    int bSize = b.size();

    vector<int> sum(aSize, 0);
    int carry = 0;

    for (int i = 0; i < aSize; i++) {
        if (i < bSize) sum[i] += b[i];

        sum[i] += a[i] + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }

    if (carry != 0) sum.push_back(carry);

    return sum;
}

int main() {
    int index;

    cin >> index;

    if (index == 0) {
        cout << 0 << endl;

        return 0;
    }

    if (index >= 1 && index <= 2) {
        cout << 1 << endl;

        return 0;
    }

    vector<int> result;
    vector<int> fibonacciCachePrevious1 = {1};
    vector<int> fibonacciCachePrevious2 = {0};

    for (int i = 2; i <= index; i++) {
        result = fibonacciCachePrevious1 + fibonacciCachePrevious2;
        fibonacciCachePrevious2 = fibonacciCachePrevious1;
        fibonacciCachePrevious1 = result;
    }

    for (int i = (int) result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }

    cout << endl;

    return 0;
}