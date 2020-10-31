#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int a[1000];
int maxLengthCache[1000];
int triggerIndexCache[1000];

void tracebackLis(int index) {
    if (index == -1) return;

    tracebackLis(triggerIndexCache[index]);

    cout << a[index] << ' ';
}

int main() {
    cin >> n;

    memset(triggerIndexCache, -1, sizeof(triggerIndexCache));

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && maxLengthCache[i] < maxLengthCache[j] + 1) {
                maxLengthCache[i] = maxLengthCache[j] + 1;
                triggerIndexCache[i] = j;
            }
        }
    }

    cout << *max_element(maxLengthCache, maxLengthCache + n) + 1 << '\n';

    tracebackLis((int) (max_element(maxLengthCache, maxLengthCache + n) - maxLengthCache));

    cout << '\n';

    return 0;
}
