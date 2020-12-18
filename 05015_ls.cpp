#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string p;
string file;
int pSize;
int fileSize;
int dp[101][101];

int memoize(int pIndex, int fileIndex) {
    int &ret = dp[pIndex][fileIndex];

    if (ret != -1) return ret;

    if (pIndex < pSize && fileIndex < fileSize && (p[pIndex] == '?' || p[pIndex] == file[fileIndex])) {
        return ret = memoize(pIndex + 1, fileIndex + 1);
    }

    if (pIndex == pSize) return ret = (fileIndex == fileSize);

    if (p[pIndex] == '*'
        && (memoize(pIndex + 1, fileIndex) == 1 || (fileIndex < fileSize && memoize(pIndex, fileIndex + 1) == 1))) {
        return ret = 1;
    }

    return ret = 0;
}

int main() {
    int n;
    vector<string> matches;

    cin >> p >> n;

    pSize = p.size();

    while (n--) {
        cin >> file;

        fileSize = file.size();

        memset(dp, -1, sizeof(dp));

        if (memoize(0, 0)) matches.push_back(file);
    }

    for (string &match : matches) {
        cout << match << '\n';
    }

    return 0;
}
