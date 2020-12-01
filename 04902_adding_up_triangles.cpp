#include <iostream>

using namespace std;

int n;
int s[401][802];
int maxValue;

void calculateMaxValueFrom(int y, int left, int right, int value) {
    if (y < 1 || y > n || left < 1 || right > 2 * y - 1) return;

    value += s[y][right] - s[y][left - 1];
    maxValue = max(maxValue, value);

    if (left % 2) calculateMaxValueFrom(y + 1, left, right + 2, value);
    else calculateMaxValueFrom(y - 1, left - 2, right, value);
}

int main() {
    int testcases = 0;

    while (true) {
        cin >> n;

        if (n == 0) return 0;

        maxValue = -16000001;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * i - 1; j++) {
                int triangleElement;

                cin >> triangleElement;

                s[i][j] = s[i][j - 1] + triangleElement;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * i - 1; j++) {
                calculateMaxValueFrom(i, j, j, 0);
            }
        }

        cout << ++testcases << ". " << maxValue << '\n';
    }
}
