#include <iostream>

using namespace std;

#define MAX_N 51

int sSize;
int officeCounts[3];
bool dp[MAX_N][MAX_N][MAX_N][3][3];
char ans[MAX_N];

bool memoize(int a, int b, int c, int p2, int p1) {
    int ansSize = a + b + c;

    if (ansSize == sSize) return a == officeCounts[0] && b == officeCounts[1] && c == officeCounts[2];

    bool &ret = dp[a][b][c][p2][p1];

    if (ret) return false;

    ret = true;
    ans[ansSize] = 'A';

    if (memoize(a + 1, b, c, p1, 0)) return true;

    if (p1 != 1) {
        ans[ansSize] = 'B';

        if (memoize(a, b + 1, c, p1, 1)) return true;
    }

    if (p2 != 2 && p1 != 2) {
        ans[ansSize] = 'C';

        if (memoize(a, b, c + 1, p1, 2)) return true;
    }

    return false;
}

int main() {
    string s;

    cin >> s;

    sSize = s.size();

    for (char si : s) {
        officeCounts[si - 'A']++;
    }

    cout << (memoize(0, 0, 0, -1, -1) ? ans : "-1") << '\n';

    return 0;
}
