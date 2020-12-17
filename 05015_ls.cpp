#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum State {
    UNKNOWN = -1,
    FALSE,
    TRUE
};

int memoize(const string &p, const string &file, vector<vector<int>> &dp, int pIndex, int fileIndex) {
    int &ret = dp[pIndex][fileIndex];

    if (ret != UNKNOWN) return ret;

    if (pIndex < p.size() && fileIndex < file.size() && (p[pIndex] == '?' || p[pIndex] == file[fileIndex])) {
        return ret = memoize(p, file, dp, pIndex + 1, fileIndex + 1);
    }

    if (pIndex == p.size()) return ret = ((fileIndex == file.size()) ? TRUE : FALSE);

    if (p[pIndex] == '*'
        && (memoize(p, file, dp, pIndex + 1, fileIndex) == TRUE
            || (fileIndex < file.size() && memoize(p, file, dp, pIndex, fileIndex + 1) == TRUE))) {
        return ret = TRUE;
    }

    return ret = FALSE;
}

int main() {
    string p;
    int n;
    vector<string> matches;

    cin >> p >> n;

    while (n-- > 0) {
        string file;

        cin >> file;

        vector<vector<int>> dp(p.size() + 1, vector<int>(file.size() + 1, UNKNOWN));

        if (memoize(p, file, dp, 0, 0)) matches.push_back(file);
    }

    for (string &match : matches) {
        cout << match << '\n';
    }

    return 0;
}
