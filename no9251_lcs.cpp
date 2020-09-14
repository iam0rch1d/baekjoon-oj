#include <iostream>

using namespace std;

int lcsLengthCache[1001][1001];

int main() {
    string a;
    string b;

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) lcsLengthCache[i + 1][j + 1] = lcsLengthCache[i][j] + 1;
            else lcsLengthCache[i + 1][j + 1] = max(lcsLengthCache[i][j + 1], lcsLengthCache[i + 1][j]);
        }
    }

    cout << lcsLengthCache[a.size()][b.size()] << endl;

    return 0;
}
