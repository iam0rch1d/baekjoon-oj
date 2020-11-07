#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    string s;
    int iFirstIndex = -1;
    int iLastIndex = 1000000;
    int ioiCount = 0;
    int pnCount = 0;

    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        if (s[i] == 'I') {
            iFirstIndex = i;

            break;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == 'I') {
            iLastIndex = i;

            break;
        }
    }

    if (iFirstIndex == -1) {
        cout << "0\n";

        return 0;
    }

    for (int i = iFirstIndex; i <= iLastIndex - 2; i++) {
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            ioiCount++;

            if (ioiCount == n) {
                pnCount++;
                ioiCount--;
            }

            i++;
        } else ioiCount = 0;
    }

    cout << pnCount << '\n';

    return 0;
}
