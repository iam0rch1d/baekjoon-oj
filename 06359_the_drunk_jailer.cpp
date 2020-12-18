#include <cstring>
#include <iostream>

using namespace std;

bool isOpened[101];

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int ans = 0;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) isOpened[j] = !isOpened[j];
        }

        for (int i = 1; i <= n; i++) {
            ans += isOpened[i];
        }

        cout << ans << '\n';

        memset(isOpened, false, sizeof(isOpened));
    }

    return 0;
}
