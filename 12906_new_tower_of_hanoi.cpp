#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    int aPegDisks;
    string aPeg;
    int bPegDisks;
    string bPeg;
    int cPegDisks;
    string cPeg;
    int diskCounts[3] = {0, 0, 0};
    map<vector<string>, int> movesFor;
    queue<vector<string>> bfsPegs;

    cin >> aPegDisks;

    if (aPegDisks) {
        cin >> aPeg;

        for (char aDisk : aPeg) {
            diskCounts[aDisk - 'A']++;
        }
    }

    cin >> bPegDisks;

    if (bPegDisks) {
        cin >> bPeg;

        for (char bDisk : bPeg) {
            diskCounts[bDisk - 'A']++;
        }
    }

    cin >> cPegDisks;

    if (cPegDisks) {
        cin >> cPeg;

        for (char cDisk : cPeg) {
            diskCounts[cDisk - 'A']++;
        }
    }

    vector<string> initialPegs{aPeg, bPeg, cPeg};

    movesFor[initialPegs] = 0;

    bfsPegs.push(initialPegs);

    while (!bfsPegs.empty()) {
        auto currentPegs = bfsPegs.front();

        bfsPegs.pop();

        for (int i = 0; i < 3; i++) {
            for (int di = 1; di <= 2; di++) {
                if (currentPegs[i].empty()) break;

                auto nextPegs = currentPegs;

                nextPegs[(i + di) % 3] += nextPegs[i].back();

                nextPegs[i].pop_back();

                if (!movesFor.count(nextPegs)) {
                    movesFor[nextPegs] = movesFor[currentPegs] + 1;

                    bfsPegs.push(nextPegs);
                }
            }
        }
    }

    cout << movesFor[{string(diskCounts[0], 'A'), string(diskCounts[1], 'B'), string(diskCounts[2], 'C')}] << '\n';

    return 0;
}
