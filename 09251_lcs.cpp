#include <iostream>

using namespace std;

int lcsLengthCache[1001][1001];

int main() {
    string a;
    string b;

    cin >> a >> b;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) lcsLengthCache[i][j] = lcsLengthCache[i - 1][j - 1] + 1;
            else lcsLengthCache[i][j] = max(lcsLengthCache[i - 1][j], lcsLengthCache[i][j - 1]);
        }
    }

    cout << lcsLengthCache[a.size()][b.size()] << endl;

    return 0;
}
