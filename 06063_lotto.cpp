#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int k;

        cin >> k;

        if (k == 0) return 0;

        vector<int> s(k);
        vector<bool> isPicked(k, false);

        for (int &element : s) {
            cin >> element;
        }

        sort(s.begin(), s.end());

        for (int i = 0; i < 6; i++) {
            isPicked[i] = true;
        }

        while (true) {
            for (int i = 0; i < k; i++) {
                if (isPicked[i]) cout << s[i] << ' ';
            }

            cout << '\n';

            if (!prev_permutation(isPicked.begin(), isPicked.end())) break;
        }

        cout << '\n';
    }
}
