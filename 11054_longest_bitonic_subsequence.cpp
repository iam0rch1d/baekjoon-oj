#include <iostream>

using namespace std;

int increaseLengthCache[1000];
int decreaseLengthCache[1000];

int main() {
    int n;
    int a[1000];
    int maxBitonicLength = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) increaseLengthCache[i] = max(increaseLengthCache[i], increaseLengthCache[j] + 1);
        }
    }

    for (int i = n - 2; i > 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) decreaseLengthCache[i] = max(decreaseLengthCache[i], decreaseLengthCache[j] + 1);
        }

        maxBitonicLength = max(maxBitonicLength, increaseLengthCache[i] + decreaseLengthCache[i] + 1);
    }

    cout << maxBitonicLength << '\n';

    return 0;
}
