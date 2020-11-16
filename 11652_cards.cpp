#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int sameCardCount = 1;
    int maxSameCardCount = 1;
    long long mostCard;

    cin >> n;

    vector<long long> cards(n);

    for (auto &card : cards) {
        cin >> card;
    }

    sort(cards.begin(), cards.end());

    mostCard = cards[0];

    for (int i = 1; i < n; i++) {
        if (cards[i] == cards[i - 1]) {
            sameCardCount++;

            if (maxSameCardCount < sameCardCount) {
                maxSameCardCount = sameCardCount;
                mostCard = cards[i];
            }
        } else sameCardCount = 1;
    }

    cout << mostCard << '\n';

    return 0;
}
