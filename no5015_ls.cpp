#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum CanMatchState {
    UNMATCHED = -1,
    FALSE,
    TRUE
};

int memoizeCanMatch(const string &pattern,
                    const string &fileName,
                    vector<vector<int>> &canMatchCache,
                    int patternCharNo,
                    int fileNameCharNo) {
    int &canMatch = canMatchCache[patternCharNo][fileNameCharNo];

    if (canMatch != UNMATCHED) return canMatch;

    if (patternCharNo < pattern.size()
        && fileNameCharNo < fileName.size()
        && (pattern[patternCharNo] == '?' || pattern[patternCharNo] == fileName[fileNameCharNo])) {
        return canMatch = memoizeCanMatch(pattern, fileName, canMatchCache, patternCharNo + 1, fileNameCharNo + 1);
    }

    if (patternCharNo == pattern.size()) return canMatch = ((fileNameCharNo == fileName.size()) ? TRUE : FALSE);

    if (pattern[patternCharNo] == '*'
        && (memoizeCanMatch(pattern, fileName, canMatchCache, patternCharNo + 1, fileNameCharNo) == TRUE
            || (fileNameCharNo < fileName.size()
                && memoizeCanMatch(pattern, fileName, canMatchCache, patternCharNo, fileNameCharNo + 1) == TRUE))) {
        return canMatch = TRUE;
    }

    return canMatch = FALSE;
}

int main() {
    string pattern;
    int numFile;
    vector<string> matches;

    cin >> pattern >> numFile;

    while (numFile-- > 0) {
        string fileName;

        cin >> fileName;

        vector<vector<int>> canMatchCache(pattern.size() + 1, vector<int>(fileName.size() + 1, UNMATCHED));

        if (memoizeCanMatch(pattern, fileName, canMatchCache, 0, 0)) matches.push_back(fileName);
    }

    for (string &match : matches) {
        cout << match << endl;
    }

    return 0;
}
