#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> methodCountCache(10001, 1);
    int t;

    for (int j = 2; j <= 3; j++) {
        for (int i = 1; i <= 10000; i++) {
            if (i - j >= 0) methodCountCache[i] += methodCountCache[i - j];
        }
    }

    cin >> t;

    while (t--) {
        int n;

        cin >> n;
        cout << methodCountCache[n] << '\n';
    }

    return 0;
}
