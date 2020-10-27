#include <iostream>
#include <vector>

using namespace std;

int maxEnergy;

void backtrackEnergy(vector<int> &w, int energy) {
    int wSize = w.size();

    if (wSize == 2) {
        maxEnergy = max(maxEnergy, energy);

        return;
    }

    for (int i = 1; i < wSize - 1; i++) {
        int toGather = w[i];

        w.erase(w.begin() + i);
        backtrackEnergy(w, energy + w[i - 1] * w[i]);
        w.insert(w.begin() + i, toGather);
    }
}

int main() {
    int n;

    cin >> n;

    vector<int> w(n);

    for (int &wi : w) {
        cin >> wi;
    }

    backtrackEnergy(w, 0);

    cout << maxEnergy << '\n';

    return 0;
}
