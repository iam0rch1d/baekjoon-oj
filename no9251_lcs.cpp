#include <iostream>

using namespace std;

int maximumLengthCache[1001][1001];

int main() {
    string a;
    string b;

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) maximumLengthCache[i + 1][j + 1] = maximumLengthCache[i][j] + 1;
            else maximumLengthCache[i + 1][j + 1] = max(maximumLengthCache[i][j + 1], maximumLengthCache[i + 1][j]);
        }
    }

    cout << maximumLengthCache[a.size()][b.size()] << endl;

    return 0;
}
