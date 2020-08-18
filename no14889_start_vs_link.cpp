#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtrackTeamDraft(vector<vector<int>> &synergy,
                        vector<bool> &isStartTeamMember,
                        vector<int> &synergyDifferences) {
    const int numPerson = (int) synergy.size() - 1;
    int numStartTeamDraft = 0;
    int indexLastStartTeamDraft = 0;
    int startTeamSynergy = 0;
    int linkTeamSynergy = 0;

    for (int i = 1; i <= numPerson; i++) {
        if (isStartTeamMember[i]) {
            numStartTeamDraft++;
            indexLastStartTeamDraft = i;
        }
    }

    if (numStartTeamDraft == numPerson / 2) {
        for (int i = 1; i <= numPerson; i++) {
            for (int j = 1; j <= numPerson; j++) {
                if (isStartTeamMember[i] && isStartTeamMember[j]) startTeamSynergy += synergy[i][j];
                else if (!isStartTeamMember[i] && !isStartTeamMember[j]) linkTeamSynergy += synergy[i][j];
            }
        }

        synergyDifferences.push_back(abs(startTeamSynergy - linkTeamSynergy));
    } else {
        for (int i = indexLastStartTeamDraft + 1; i <= numPerson; i++) {
            isStartTeamMember[i] = true;

            backtrackTeamDraft(synergy, isStartTeamMember, synergyDifferences);

            isStartTeamMember[i] = false;
        }
    }
}

int main() {
    int numPerson;
    vector<int> synergyDifferences;

    cin >> numPerson;

    vector<vector<int>> synergy(numPerson + 1, vector<int> (numPerson + 1));
    vector<bool> isStartTeamMember(numPerson + 1, false);

    for (int i = 1; i <= numPerson; i++) {
        for (int j = 1; j <= numPerson; j++) {
            cin >> synergy[i][j];
        }
    }

    backtrackTeamDraft(synergy, isStartTeamMember, synergyDifferences);

    cout << *min_element(synergyDifferences.begin(), synergyDifferences.end()) << endl;

    return 0;
}
