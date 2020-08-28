#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int numPerson;
    int personToEliminate;
    queue<int> roundtable;
    vector<int> josephusPermutation;

    cin >> numPerson >> personToEliminate;

    for (int i = 1; i <= numPerson; i++) {
        roundtable.push(i);
    }

    while (!roundtable.empty()) {
        for (int i = 0; i < personToEliminate - 1; i++) {
            roundtable.push(roundtable.front());
            roundtable.pop();
        }

        josephusPermutation.push_back(roundtable.front());
        roundtable.pop();
    }

    cout << "<";

    for (int &person : josephusPermutation) {
        printf("%d", person);

        if (person != josephusPermutation.back()) {
            printf(", ");
        }
    }

    cout << ">" << endl;

    return 0;
}
